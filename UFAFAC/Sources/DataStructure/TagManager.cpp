#include "DataStructure/TagManager.hpp"
#include <regex>
#include <assert.h>

#include "Utils.h"
#include "DataStructure/DataBase.hpp"

using namespace DataStructure;

TagManager::TagManager()
{
}

TagManager::~TagManager()
{
}

bool TagManager::IsTagValid(u32 index)
{
	if (index >= tags.size()) return false;
	for (auto slot : availableSlots)
	{
		if (slot == index) return false;
	}
	return true;
}

u32 TagManager::FindTag(const std::wstring& tag)
{
	for (u32 i = 0; i < (u32)tags.size(); ++i)
	{
		if (tags[i].GetName() == tag) return i;
	}
	return ~0u;
}

u32 TagManager::AddTag(const std::wstring& tag)
{
	u32 result = FindTag(tag);
	if (result != ~0u) return result;
	if (!availableSlots.empty())
	{
		result = availableSlots.back();
		tags[result] = Tag(tag);
		availableSlots.pop_back();
		return result;
	}
	tags.push_back(std::move(Tag(tag)));
	return (u32)tags.size() - 1;
}

void TagManager::RemoveTag(u32 index, DataBase& dataBase)
{
	if (!IsTagValid(index)) return;
	availableSlots.push_back(index);
	tags[index] = std::move(Tag(L""));
	dataBase.OnDeleteTag(index);
}

std::vector<Tag> TagManager::GetTagsByName(const std::wstring& tag)
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

std::vector<Tag> TagManager::GetTags()
{
	if (availableSlots.empty()) return tags;
	std::vector<Tag> result;
	for (u32 i = 0; i < (u32)tags.size(); ++i)
	{
		bool found = false;
		for (auto slot : availableSlots)
		{
			if (slot == i)
			{
				found = true;
				break;
			}
		}
		if (!found) result.push_back(tags[i]);
	}
	return result;
}