#pragma once

#include <string>
#include <vector>
#include <unordered_map>

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
		StringInfo(const std::wstring& str) : entry(str), refCount(0) {}
	};

	class StringsHolder
	{
	public:
		StringsHolder() = default;

		~StringsHolder() = default;

		const std::wstring& GetString(u32 index);
		void IncrementRef(u32 index);
		void DecrementRef(u32 index);
		void ReleaseString(u32 index);

		u32 FindOrCreateString(const std::wstring& str);
		u32 FindString(const std::wstring& str);

	private:
		std::vector<StringInfo> strings;
		std::vector<u32> availableSlots;
		std::unordered_map<std::wstring, u32> unorderedStrings;

		friend Parsing::FileParser;
	};

}