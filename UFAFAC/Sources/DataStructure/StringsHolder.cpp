#include "DataStructure/StringsHolder.hpp"

#include <assert.h>

using namespace DataStructure;

const std::wstring& StringsHolder::GetString(u64 index)
{
	assert(index < strings.size());
	strings[index].refCount++;
	return strings[index].entry;
}

void StringsHolder::IncrementRef(u64 index)
{
	assert(index < strings.size());
	strings[index].refCount++;
}

void StringsHolder::DecrementRef(u64 index)
{
	assert(index < strings.size());
	strings[index].refCount--;
}

void StringsHolder::ReleaseString(u64 index)
{
	assert(index < strings.size() && strings[index].refCount);
	strings[index].refCount--;
	if (!strings[index].refCount)
	{
		availableSlots.push_back(index);
		unorderedStrings.erase(strings[index].entry);
	}
}

u64 StringsHolder::FindOrCreateString(const std::wstring& str)
{
	u64 res = FindString(str);
	if (res != -1) return res;
	if (!availableSlots.empty())
	{
		u64 slot = availableSlots.front();
		strings[slot] = StringInfo(str);
		unorderedStrings.insert(std::pair<std::wstring, u64>(str, slot));
		std::copy(availableSlots.data() + 1, availableSlots.data() + availableSlots.size(), availableSlots.data());
		availableSlots.pop_back();
		return slot;
	}
	StringInfo info = StringInfo(str);
	strings.push_back(str);
	unorderedStrings.insert(std::pair<std::wstring, u64>(str, strings.size() - 1));
	return strings.size() - 1;
}

u64 StringsHolder::FindString(const std::wstring& str)
{
	auto t = unorderedStrings.find(str);
	if (t != unorderedStrings.end())
	{
		return t->second;
	}
	return -1;
}