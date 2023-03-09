#pragma once
#include <vector>

#include "Tag.h"
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

		void AddTag(const std::wstring& tag);
		std::vector<Tag> GetTags();
	private:
		std::vector<Tag> tags;
		static TagManager* tagManager;
	};
}