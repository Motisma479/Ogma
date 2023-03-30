#pragma once
#include <vector>
#include <unordered_map>

#include "Tag.h"
#include "Core/Types.hpp"
namespace DataStructure
{
	struct TagListInfo
	{
		std::vector<u32> tags;
		u32 refCount;

		TagListInfo() : refCount(0) {}
		TagListInfo(std::vector<u32>&& str) : tags(str), refCount(0) {}
		TagListInfo(const std::vector<u32>& str) : tags(str), refCount(0) {}
	};
	class u32_vector_hasher
	{
	public:
		std::size_t operator()(std::vector<u32> const& vec) const
		{
			std::size_t seed = vec.size();
			for (auto x : vec)
			{
				x = ((x >> 16) ^ x) * 0x45d9f3b;
				x = ((x >> 16) ^ x) * 0x45d9f3b;
				x = (x >> 16) ^ x;
				seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}
	};
	class TagManager
	{
	public:
		TagManager();
		~TagManager();

		static void Initialize();

		static TagManager& Get() { return *tagManager; }

		static void Delete();

		void AddTag(const std::wstring& tag);

		void RemoveTag(const std::wstring& tag);

		bool IsInside(const std::wstring& tag);

		std::vector<Tag> GetTagsByName(const std::wstring& tag);

		std::vector<Tag> GetTags();

		const std::vector<u32>& GetTagList(u32 index);
		void IncrementRef(u32 index);
		void DecrementRef(u32 index);
		void ReleaseTagList(u32 index);

		u32 FindOrCreateTagList(const std::vector<u32>& list);
		u32 FindTagList(const std::vector<u32>& list);
	private:
		std::vector<Tag> tags;
		std::vector<TagListInfo> tagsInUse;
		std::vector<u32> availableSlots;
		std::unordered_map<std::vector<u32>, u32, u32_vector_hasher> unorderedTags;
		static TagManager* tagManager;
	};
}