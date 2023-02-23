#include "DataStructure/StringsHolder.hpp"

#include <assert.h>

using namespace DataStructure;

const std::wstring& StringsHolder::GetString(u32 index)
{
	assert(index < strings.size());
	strings[index].refCount++;
	return strings[index].entry;
}

void StringsHolder::ReleaseString(u32 index)
{
	assert(index < strings.size() && strings[index].refCount);
	strings[index].refCount--;
}