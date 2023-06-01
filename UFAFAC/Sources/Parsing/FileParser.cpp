#include "Parsing/FileParser.hpp"

#include "Parsing/Deserializer.hpp"
#include "Parsing/Serializer.hpp"

#include <filesystem>
#include <fstream>

using namespace Parsing;
std::filesystem::path mainFile = std::filesystem::current_path().append("Data/DataBase.bin");
std::filesystem::path strFile = std::filesystem::current_path().append("Data/Strings.bin");
std::filesystem::path tagFile = std::filesystem::current_path().append("Data/Tags.bin");

bool FileParser::ReadMainFile(DataStructure::DataBase& dataBase)
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

	auto exitFunc = [&](bool returnValue) -> bool
	{
		delete[] FileData;
		FileData = nullptr;
		return returnValue;
	};

	file.read(reinterpret_cast<char*>(FileData), dataSize);
	file.close();
	Deserializer dr(FileData, dataSize);
	if (!dr.Read(dataBase.availableSlots)) return exitFunc(false);
	u64 dataBaseSize = 0;
	if (!dr.Read(dataBaseSize)) return exitFunc(false);
	for (u64 i = 0; i < dataBaseSize; ++i)
	{
		DataStructure::DataBaseEntry entry;
		if (!dr.Read(entry.name) || !dr.Read(entry.description) || !dr.Read(entry.authors) || !dr.Read(entry.tags) || !dr.Read(entry.date)) return false;
		dataBase.datas.push_back(std::move(entry));
	}
	return exitFunc(true);
}

bool FileParser::WriteMainFile(const DataStructure::DataBase& dataBase)
{
	Serializer sr;
	sr.Write(dataBase.availableSlots);
	sr.Write(dataBase.datas.size());
	for (u64 i = 0; i < dataBase.datas.size(); i++)
	{
		sr.Write(dataBase.datas[i].name);
		sr.Write(dataBase.datas[i].description);
		sr.Write(dataBase.datas[i].authors);
		sr.Write(dataBase.datas[i].tags);
		sr.Write(dataBase.datas[i].date);
	}
	std::ofstream file(mainFile, std::ios::binary |std::ios::trunc);
	if (file.fail())
	{
		file.close();
		return false;
	}
	file.write(reinterpret_cast<const char*>(sr.GetBuffer()), sr.GetBufferSize());
	file.close();
	return true;
}

bool Parsing::FileParser::ReadTags(DataStructure::TagManager& tags)
{
	if (!std::filesystem::exists(tagFile))
	{
		return false;
	}
	std::ifstream file(tagFile, std::ios::ate | std::ios::binary);
	if (file.fail())
	{
		file.close();
		return false;
	}
	u64 dataSize = file.tellg();
	file.seekg(0, std::ios_base::beg);
	u8* FileData = new u8[dataSize];

	auto exitFunc = [&](bool returnValue) -> bool
	{
		delete[] FileData;
		FileData = nullptr;
		return returnValue;
	};

	file.read((char*)FileData, dataSize);
	file.close();
	Parsing::Deserializer dr(FileData, dataSize);
	if (!dr.Read(tags.availableSlots)) return exitFunc(false);
	u64 tagCount = 0;
	if (!dr.Read(tagCount)) return exitFunc(false);
	for (u64 i = 0; i < tagCount; ++i)
	{
		std::wstring entry;
		if (!dr.Read(entry)) return exitFunc(false);
		tags.tags.push_back(std::move(entry));
	}
	return exitFunc(true);
}

bool Parsing::FileParser::WriteTags(const DataStructure::TagManager& tags)
{
	Serializer sr;
	sr.Write(tags.availableSlots);
	sr.Write(tags.tags.size());
	for (u64 i = 0; i < tags.tags.size(); i++)
	{
		sr.Write(tags.tags[i].name);
	}
	std::ofstream file(tagFile, std::ios::binary | std::ios::trunc);
	if (file.fail())
	{
		file.close();
		return false;
	}
	file.write(reinterpret_cast<const char*>(sr.GetBuffer()), sr.GetBufferSize());
	file.close();
	return true;
}
