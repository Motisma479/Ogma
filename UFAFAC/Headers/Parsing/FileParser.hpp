#pragma once

#include <vector>

#include "DataStructure/TagManager.hpp"
#include "DataStructure/DataBase.hpp"

namespace Parsing
{
	class Serializer;
	class Deserializer;

	class FileParser
	{
	public:
		FileParser() = default;

		~FileParser() = default;

		static bool ReadMainFile(DataStructure::DataBase& dataBase, Deserializer& dr);

		static void WriteMainFile(const DataStructure::DataBase& dataBase, Serializer& sr);

		static bool ReadFromFile(DataStructure::DataBase& dataBase);

		static bool SaveToFile(const DataStructure::DataBase& dataBase);

	private:
		static bool ReadTags(DataStructure::TagManager& tags, Deserializer& dr);

		static void WriteTags(const DataStructure::TagManager& tags, Serializer& sr);
	};

}