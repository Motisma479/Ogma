#include "Parsing/FileParser.hpp"

#include "Parsing/Deserializer.hpp"
#include "Parsing/Serializer.hpp"

#include <filesystem>
#include <fstream>

using namespace Parsing;
std::filesystem::path mainFile = std::filesystem::current_path().append("Data/DataBase.bin");

bool FileParser::ReadMainFile(DataStructure::DataBase& dataBase, DataStructure::StringsHolder& strings)
{
	if (!std::filesystem::exists(mainFile))
	{
		return false;
	}
	std::ifstream file(mainFile, std::ios::ate | std::ios::binary);
	if (file.fail())
	{
		file.close();
		return false;
	}
	u64 dataSize = file.tellg();
	file.seekg(0, std::ios_base::beg);
	u8* FileData = new u8[dataSize];
	file.read((char*)FileData, dataSize);
	file.close();
	Parsing::Deserializer dr(FileData, dataSize);
	while (dr.CursorPos() != dr.BufferSize())
	{
		DataStructure::DataBaseEntry entry;
		u32 nameIndex, descIndex, authIndex, tagIndex;
		s64 unTime;
		if (!dr.Read(nameIndex) || !dr.Read(descIndex) || !dr.Read(authIndex) || !dr.Read(tagIndex) || !dr.Read(unTime)) break;
		entry.name = strings.GetString(nameIndex);
		entry.authors = strings.GetString(authIndex);
		entry.description = strings.GetString(descIndex);
		entry.date = unTime;
	}
}

void FileParser::WriteMainFile(const DataStructure::DataBase& dataBase)
{

}

void FileParser::ReadStrings(DataStructure::StringsHolder& strings)
{

}

void FileParser::WriteStrings(const DataStructure::StringsHolder& dataBase)
{

}