#pragma once

#include <vector>

#include "DataStructure/StringsHolder.hpp"
#include "DataStructure/DataBase.hpp"

namespace Parsing
{
	class FileParser
	{
	public:
		FileParser() = default;

		~FileParser() = default;

		bool ReadMainFile(DataStructure::DataBase& dataBase, DataStructure::StringsHolder& strings);

		void WriteMainFile(const DataStructure::DataBase& dataBase);

		void ReadStrings(DataStructure::StringsHolder& strings);

		void WriteStrings(const DataStructure::StringsHolder& dataBase);

	private:

	};

}