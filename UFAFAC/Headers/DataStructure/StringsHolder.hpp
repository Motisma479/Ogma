#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"

namespace Parsing
{
	class FileParser;
}

namespace DataStructure
{
	struct StringInfo
	{
		std::wstring entry;
		u32 refCount;

		StringInfo() : refCount(0) {}
		StringInfo(std::wstring&& str) : entry(str), refCount(0) {}
	};

	class StringsHolder
	{
	public:
		StringsHolder() = default;

		~StringsHolder() = default;

		const std::wstring& GetString(u32 index);
		void ReleaseString(u32 index);

	private:
		std::vector<StringInfo> strings;

		friend Parsing::FileParser;
	};

}