#include "DataStructure/TagManager.hpp"
#include "Utils.h"
#include <algorithm>
#include <regex>

DataStructure::TagManager* DataStructure::TagManager::tagManager;

DataStructure::TagManager::TagManager()
{
}

DataStructure::TagManager::~TagManager()
{
}

void DataStructure::TagManager::Initialize()
{
	tagManager = new DataStructure::TagManager();
}

void DataStructure::TagManager::Delete()
{
	delete tagManager;
}

void DataStructure::TagManager::AddTag(const std::wstring& tag)
{
	this->tags.push_back(Tag(tag));
}


void DataStructure::TagManager::RemoveTag(const std::wstring& tag)
{
	tags.erase(std::remove_if(tags.begin(), tags.end(), [tag](const Tag& o) { return tag == o.GetName(); }), tags.end());
}

bool DataStructure::TagManager::IsInside(const std::wstring& tag)
{
	return std::find_if(tags.begin(), tags.end(), [tag](const Tag& o) { return Utils::ToLower(tag) == Utils::ToLower(o.GetName()); }) != tags.end();
}

std::vector<Tag> DataStructure::TagManager::GetTagsByName(const std::wstring& tag)
{
	std::wregex regexSearch(Utils::ToLower(tag));

	std::vector<Tag> out;

	for (const auto& str : tags) {
		if (std::regex_search(Utils::ToLower(str.GetName()), regexSearch)) {
			out.push_back(str);
		}
	}
	return out;
}

std::vector<Tag> DataStructure::TagManager::GetTags()
{
	return tags;
}
