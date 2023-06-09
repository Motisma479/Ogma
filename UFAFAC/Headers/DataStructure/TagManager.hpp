#pragma once
#include <vector>
#include <unordered_map>

#include "Tag.h"
#include "Core/Types.hpp"

namespace Parsing
{
	class FileParser;
}

namespace DataStructure
{
	class DataBase;

	class TagManager
	{
	public:
		TagManager();
		~TagManager();

		u32 AddTag(const std::wstring& tag);

		// Warning : will only find a tag with an exact match, use "GetTagsByName" if you want to search the tags
		u32 FindTag(const std::wstring& tag);

		bool IsTagValid(u32 index);

		// Warning : this will remove the tag AND update all of the database to remove the tag of all files, which can take a large amount of time
		void RemoveTag(u32 index, DataBase& dataBase);

		std::vector<Tag> GetTagsByName(const std::wstring& tag);

		std::vector<Tag> GetTags();
	private:
		std::vector<Tag> tags;
		std::vector<u32> availableSlots;

		friend Parsing::FileParser;
	};
}