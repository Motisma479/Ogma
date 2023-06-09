#include "Parsing/FileParser.hpp"

#include "Parsing/Deserializer.hpp"
#include "Parsing/Serializer.hpp"

#include <filesystem>
#include <fstream>

using namespace Parsing;
std::filesystem::path mainFile = std::filesystem::current_path().append("Data/DataBase.bin");
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
		if (!dr.Read(entry.name) || !dr.Read(entry.description) || !dr.Read(entry.authors) || !dr.Read(entry.tags) || !dr.Read(entry.date)) return exitFunc(false);
		u64 fileCount = 0;
		if (!dr.Read(fileCount)) return exitFunc(false);
		entry.files.resize(fileCount);
		for (u64 j = 0; j < fileCount; ++j)
		{
			if (!dr.Read(entry.files[j])) return exitFunc(false);
		}
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
		auto& entry = dataBase.datas[i];
		sr.Write(entry.name);
		sr.Write(entry.description);
		sr.Write(entry.authors);
		sr.Write(entry.tags);
		sr.Write(entry.date);
		sr.Write(entry.files.size());
		for (u64 j = 0; j < entry.files.size(); j++)
		{
			sr.Write(entry.files[j]);
		}
	}
	if (!std::filesystem::exists(mainFile.parent_path()))
	{
		std::filesystem::create_directories(mainFile.parent_path());
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
	if (!std::filesystem::exists(tagFile.parent_path()))
	{
		std::filesystem::create_directories(tagFile.parent_path());
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
