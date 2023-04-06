#include "DataStructure/StringsHolder.hpp"

#include <assert.h>

using namespace DataStructure;

const std::wstring& StringsHolder::GetString(u32 index)
{
	assert(index < strings.size());
	return strings[index].entry;
}

void StringsHolder::IncrementRef(u32 index)
{
	assert(index < strings.size());
	strings[index].refCount++;
}

void StringsHolder::DecrementRef(u32 index)
{
	assert(index < strings.size());
	strings[index].refCount--;
	if (!strings[index].refCount)
	{
		availableSlots.push_back(index);
		unorderedStrings.erase(strings[index].entry);
	}
}

void StringsHolder::ReleaseString(u32 index)
{
	assert(index < strings.size());
	strings[index].refCount = 0;
	availableSlots.push_back(index);
	unorderedStrings.erase(strings[index].entry);
}

u32 StringsHolder::FindOrCreateString(const std::wstring& str)
{
	u32 res = FindString(str);
	if (res != -1) return res;
	if (!availableSlots.empty())
	{
		u32 slot = availableSlots.front();
		strings[slot] = StringInfo(str);
		unorderedStrings.insert(std::pair<std::wstring, u32>(str, slot));
		std::copy(availableSlots.data() + 1, availableSlots.data() + availableSlots.size(), availableSlots.data());
		availableSlots.pop_back();
		return slot;
	}
	strings.push_back(str);
	unorderedStrings.insert(std::pair<std::wstring, u32>(str, static_cast<u32>(strings.size() - 1)));
	return static_cast<u32>(strings.size() - 1);
}

u32 StringsHolder::FindString(const std::wstring& str)
{
	auto t = unorderedStrings.find(str);
	if (t != unorderedStrings.end())
	{
		return t->second;
	}
	return -1;
}