#include "ReleaseData.hpp"

#include<iostream>
#include <string>
#include <curl/curl.h>

namespace OGMA
{
    ReleaseData::ReleaseData() : status(ReleaseStatus::NEW_VERSION), nameReceived(nullptr) {}
    ReleaseData::~ReleaseData()
    {
        if (nameReceived)
            delete[] nameReceived;
    }

    ReleaseData::ReleaseData(const ReleaseData& other) : status(ReleaseStatus::NEW_VERSION), nameReceived(nullptr)
    {
        operator = (other);
    }
    ReleaseData& ReleaseData::operator=(const ReleaseData& other)
    {
        status = other.status;
        if (nameReceived)
            delete[] nameReceived;
        if (other.nameReceived)
        {
            size_t strlen = std::strlen(other.nameReceived);
            nameReceived = new char[strlen + 1];
            strcpy(nameReceived, other.nameReceived);
        }
        return *this;
    }

    size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t total_size = size * nmemb;
        output->append((char*)contents, total_size);
        return total_size;
    }

    ReleaseData ReleaseData::GetLatestData(const char* repoOwner, const char* repoName, const char* expectedReleaseName) {
        std::string url;
        url = url + "https://github.com/" + repoOwner + "/" + repoName + "/releases/latest";

        ReleaseData result;
        result.status = ReleaseStatus::CRIT_ERR;

        //could use GitHub api but didn't understand how it's working so will be set on FIXME 

        curl_global_init(CURL_GLOBAL_DEFAULT);
        CURL* curl = curl_easy_init();
        CURLcode res;

        if (!curl)
        {
            curl_global_cleanup();
            return result;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Set up callback to receive the response
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the HTTP request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
        {
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            result.status = ReleaseStatus::ERR_NO_CONNECTION;
            return result;
        }

        size_t pos = response.find("/Motisma479/Ogma/tree/");
        if (pos != std::string::npos) {
            size_t endPos = response.find_first_of("\"", pos + 22);
            std::string latestReleaseName = response.substr(pos + 22, endPos - pos - 22);

            result.nameReceived = new char[latestReleaseName.length() + 1];
            latestReleaseName.copy(result.nameReceived, latestReleaseName.size(), 0);
            result.nameReceived[latestReleaseName.length()] = '\0';

            // Compare the release names
            if (latestReleaseName == expectedReleaseName)
            {
                result.status = ReleaseStatus::MATCH;
            }
            else
            {
                float expected = std::stof(std::string(expectedReleaseName).erase(0, 1));
                float latest = std::stof(latestReleaseName.erase(0, 1));

                if (expected > latest)
                    result.status = ReleaseStatus::SUPERIOR_VERSION;
                else
                    result.status = ReleaseStatus::NEW_VERSION;
            }
        }
        else {
            std::cerr << "Error: Could not find release name in the response." << std::endl;
        }

        curl_easy_cleanup(curl);

        curl_global_cleanup();
        return result;
    }
}