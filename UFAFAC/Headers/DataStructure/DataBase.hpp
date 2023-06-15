#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"
#include "DataBaseEntry.hpp"
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

		inline System::String^ ToString()
		{
			return (day<10 ? "0" : "") + day.ToString() + " / " + (month < 10 ? "0" : "") + month.ToString() + " / " + year.ToString();
		}
	};

	class DataBase
	{
	public:
		DataBase() = default;

		~DataBase() = default;

		static DataBase& Get() { return *dataBase; }

		static void Initialize();

		static void Delete();

		u32 CreateEntry();

		void DeleteEntry(u32 index);

		DataBaseEntry& GetEntryByIndex(u32 index);

		std::vector<u32> GetEntries();
		std::vector<u32> GetEntriesByName(const std::wstring& name);
		std::vector<u32> GetEntriesByAuthor(const std::wstring& author);
		std::vector<u32> GetEntriesByLocation(const std::wstring& location);
		std::vector<u32> GetEntriesByEdition(const std::wstring& edition);
		std::vector<u32> GetEntriesByDescription(const std::wstring& desc);
		std::vector<u32> GetEntriesByTimeStamp(s64 lower, s64 upper);
		std::vector<u32> GetEntriesByTags(const std::vector<u32>& tagList, bool requireAllTags);

		// Will return -1 if date is invalid, year range is [-2000; 6000]
		s64 TimeStampFromDate(const Date& dateIn);
		Date DateFromTimeStamp(s64 tmIn);

		TagManager tags;
		// TODO Remove
		void CreateRandomEntries(u64 count);
		// TODO Remove
		void CreateRandomTags(u64 count);
		// TODO Remove
		const std::vector<DataBaseEntry>& GetRawDatas() { return datas; }

	private:
		static DataBase* dataBase;
		std::vector<DataBaseEntry> datas;
		std::vector<u32> availableSlots;

		void OnDeleteTag(u32 index);

		friend Parsing::FileParser;
		friend TagManager;
	};
}