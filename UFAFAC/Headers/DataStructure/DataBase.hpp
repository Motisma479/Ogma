#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"
#include "DataBaseEntry.hpp"

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

	private:
		static DataBase* dataBase;
		std::vector<DataBaseEntry> datas;

		friend Parsing::FileParser;
	};
}