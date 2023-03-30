#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"
#include "DataBaseEntry.hpp"
#include "StringsHolder.hpp"
#include "TagManager.hpp"

namespace Parsing
{
	class FileParser;
}

namespace DataStructure
{
	struct Date
	{
		s32 year;
		u8 month;
		u8 day;
	};

	class DataBase
	{
	public:
		DataBase() = default;

		~DataBase() = default;

		static DataBase& Get() { return *dataBase; }

		static void Initialize();

		static void Delete();

		u32 PushEntry();

		void DeleteEntry(u32 index);

		const DataBaseEntry& GetEntryByIndex(u32 index);

		std::vector<const DataBaseEntry*> GetEntriesByName(const std::wstring& name);
		std::vector<const DataBaseEntry*> GetEntriesByAuthor(const std::wstring& author);
		std::vector<const DataBaseEntry*> GetEntriesByLocation(const std::wstring& location);
		std::vector<const DataBaseEntry*> GetEntriesByEdition(const std::wstring& edition);
		std::vector<const DataBaseEntry*> GetEntriesByDescription(const std::wstring& desc);
		std::vector<const DataBaseEntry*> GetEntriesByTimeStamp(s64 lower, s64 upper);
		std::vector<const DataBaseEntry*> GetEntriesByTags(const std::vector<u32>& tagList);

		// Will return -1 if date is invalid, year range is [-2000; 6000]
		s64 TimeStampFromDate(const Date& dateIn);
		Date DateFromTimeStamp(s64 tmIn);

	private:
		static DataBase* dataBase;
		StringsHolder strings;
		TagManager tags;
		std::vector<DataBaseEntry> datas;
		std::vector<u32> availableSlots;

		void ReferenceStrings();

		friend Parsing::FileParser;
	};
}