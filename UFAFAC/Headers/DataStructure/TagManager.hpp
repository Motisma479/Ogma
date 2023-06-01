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
	class TagManager
	{
	public:
		TagManager();
		~TagManager();

		static void Initialize();

		static TagManager& Get() { return *tagManager; }

		static void Delete();

		u32 AddTag(const std::wstring& tag);

		// Warning : will only find a tag with an exact match, use "GetTagsByName" if you want to search the tags
		u32 FindTag(const std::wstring& tag);

		bool IsTagValid(u32 index);

		void RemoveTag(const std::wstring& tag);
		void RemoveTag(u32 index);

		std::vector<Tag> GetTagsByName(const std::wstring& tag);

		std::vector<Tag> GetTags();
	private:
		std::vector<Tag> tags;
		std::vector<u32> availableSlots;
		static TagManager* tagManager;

		friend Parsing::FileParser;
	};
}