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

		const std::wstring& GetString(u64 index);
		void IncrementRef(u64 index);
		void DecrementRef(u64 index);
		void ReleaseString(u64 index);

		u64 FindOrCreateString(const std::wstring& str);
		u64 FindString(const std::wstring& str);

	private:
		std::vector<StringInfo> strings;
		std::vector<u64> availableSlots;
		std::unordered_map<std::wstring, u64> unorderedStrings;

		friend Parsing::FileParser;
	};

}