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

		std::vector<const DataBaseEntry&> GetEntriesByName(const std::wstring& name);

	private:
		static DataBase* dataBase;
		StringsHolder strings;
		std::vector<DataBaseEntry> datas;

		void ReferenceStrings();

		friend Parsing::FileParser;
	};
}