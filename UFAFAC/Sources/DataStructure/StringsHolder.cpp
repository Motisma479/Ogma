#include "DataStructure/StringsHolder.hpp"

#include <assert.h>

using namespace DataStructure;

const std::string& StringsHolder::GetString(u32 index)
{
	assert(index < strings.size());
	refCounts[index]++;
}

void StringsHolder::ReleaseString(u32 index)
{
	assert(index < strings.size() && refCounts[index]);
	refCounts[index]--;
}