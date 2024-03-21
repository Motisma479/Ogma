#pragma once
namespace OGMA
{
    enum class ReleaseStatus : int
    {
        CRIT_ERR = -2,
        ERR_NO_CONNECTION = -1,
        MATCH = 0,
        NEW_VERSION,
        SUPERIOR_VERSION //Normaly not a normal state if using a release
    };
    class ReleaseData
    {
    public:
        ReleaseData();
        ~ReleaseData();

        ReleaseData(const ReleaseData& other);
        ReleaseData& operator=(const ReleaseData& other);

        static ReleaseData GetLatestData(const char* repoOwner, const char* repoName, const char* expectedReleaseName);

        ReleaseStatus status;
        char* nameReceived;
    };
}