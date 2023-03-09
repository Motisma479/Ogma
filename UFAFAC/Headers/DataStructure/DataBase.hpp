#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"
#include "DataBaseEntry.hpp"
#include "StringsHolder.hpp"

namespace Parsing
{
	class FileParser;
}

namespace DataStructure
{
	class DataBase
	{
	public:
		DataBase() = default;

		~DataBase() = default;

		static DataBase& Get() { return *dataBase; }

		static void Initialize();

		static void Delete();

		u64 PushEntry();

		const DataBaseEntry& GetEntryByIndex(u64 index);

		std::vector<const DataBaseEntry*> GetEntriesByName(const std::wstring& name);
		std::vector<const DataBaseEntry*> GetEntriesByAuthor(const std::wstring& author);
		std::vector<const DataBaseEntry*> GetEntriesByDescription(const std::wstring& desc);
		std::vector<const DataBaseEntry*> GetEntriesByTimeStamp(s64 lower, s64 upper);

		std::wstring ToLower(const std::wstring& in);

	private:
		static DataBase* dataBase;
		StringsHolder strings;
		std::vector<DataBaseEntry> datas;

		void ReferenceStrings();

		friend Parsing::FileParser;
	};
}