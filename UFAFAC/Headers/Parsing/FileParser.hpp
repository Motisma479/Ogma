#pragma once

#include <vector>

#include "DataStructure/TagManager.hpp"
#include "DataStructure/DataBase.hpp"

namespace Parsing
{
	class FileParser
	{
	public:
		FileParser() = default;

		~FileParser() = default;

		bool ReadMainFile(DataStructure::DataBase& dataBase);

		bool WriteMainFile(const DataStructure::DataBase& dataBase);

		bool ReadTags(DataStructure::TagManager& tags);

		bool WriteTags(const DataStructure::TagManager& tags);

	private:

	};

}