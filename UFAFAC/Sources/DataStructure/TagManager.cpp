#include "DataStructure/TagManager.hpp"
#include "Utils.h"
#include <regex>
#include <assert.h>

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
	for (const auto& str : tags)
	{
		if (std::regex_search(Utils::ToLower(str.GetName()), regexSearch))
		{
			out.push_back(str);
		}
	}
	return out;
}

std::vector<Tag> DataStructure::TagManager::GetTags()
{
	return tags;
}

const std::vector<u32>& DataStructure::TagManager::GetTagList(u32 index)
{
	assert(index < tagsInUse.size());
	return tagsInUse[index].tags;
}

void DataStructure::TagManager::IncrementRef(u32 index)
{
	assert(index < tagsInUse.size());
	tagsInUse[index].refCount++;
}

void DataStructure::TagManager::DecrementRef(u32 index)
{
	assert(index < tagsInUse.size());
	tagsInUse[index].refCount--;
	if (!tagsInUse[index].refCount)
	{
		availableSlots.push_back(index);
		unorderedTags.erase(tagsInUse[index].tags);
	}
}

void DataStructure::TagManager::ReleaseTagList(u32 index)
{
	assert(index < tagsInUse.size());
	tagsInUse[index].refCount = 0;
	availableSlots.push_back(index);
	unorderedTags.erase(tagsInUse[index].tags);
}

u32 DataStructure::TagManager::FindOrCreateTagList(const std::vector<u32>& list)
{
	u32 res = FindTagList(list);
	if (res != -1) return res;
	if (!availableSlots.empty())
	{
		u32 slot = availableSlots.front();
		tagsInUse[slot] = TagListInfo(list);
		unorderedTags.insert(std::pair<std::vector<u32>, u32>(list, slot));
		std::copy(availableSlots.data() + 1, availableSlots.data() + availableSlots.size(), availableSlots.data());
		availableSlots.pop_back();
		return slot;
	}
	tagsInUse.push_back(list);
	unorderedTags.insert(std::pair<std::vector<u32>, u32>(list, (u32)tagsInUse.size() - (u32)1));
	return (u32)tagsInUse.size() - (u32)1;
}

u32 DataStructure::TagManager::FindTagList(const std::vector<u32>& list)
{
	auto t = unorderedTags.find(list);
	if (t != unorderedTags.end())
	{
		return t->second;
	}
	return -1;
}
