#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"

namespace DataStructure
{
	class StringsHolder
	{
	public:
		StringsHolder() = default;

		~StringsHolder() = default;

		const std::string& GetString(u32 index);
		void ReleaseString(u32 index);
	private:
		std::vector<std::string> strings;
		std::vector<u32> refCounts;
	};

}