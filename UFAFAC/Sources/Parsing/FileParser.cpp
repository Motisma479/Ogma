#include "Parsing/FileParser.hpp"

#include "Parsing/Deserializer.hpp"
#include "Parsing/Serializer.hpp"

#include <filesystem>
#include <fstream>

using namespace Parsing;
std::filesystem::path mainFile = std::filesystem::current_path().append("Data/DataBase.bin");
std::filesystem::path strFile = std::filesystem::current_path().append("Data/Strings.bin");

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
	u64 avEntr;
	if (!dr.Read(avEntr)) return exitFunc(false);
	for (u64 i = 0; i < avEntr; i++)
	{
		dataBase.availableSlots.push_back(0);
		if (!dr.Read(dataBase.availableSlots.back())) return exitFunc(false);
	}
	while (dr.CursorPos() != dr.BufferSize())
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
	sr.Write(dataBase.availableSlots.size());
	for (u64 i = 0; i < dataBase.availableSlots.size(); i++)
	{
		sr.Write(dataBase.availableSlots[i]);
	}
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

bool FileParser::ReadStrings(DataStructure::StringsHolder& strings)
{
	if (!std::filesystem::exists(strFile))
	{
		return false;
	}
	std::ifstream file(strFile, std::ios::ate | std::ios::binary);
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
	u64 avStr;
	if (!dr.Read(avStr)) return exitFunc(false);
	for (u64 i = 0; i < avStr; i++)
	{
		strings.availableSlots.push_back(0);
		if (!dr.Read(strings.availableSlots.back())) return exitFunc(false);
	}
	while (dr.CursorPos() != dr.BufferSize())
	{
		std::wstring entry;
		u32 stringSize;
		if (!dr.Read(stringSize) || !dr.Read(entry, stringSize)) return exitFunc(false);
		strings.unorderedStrings.insert(std::pair<std::wstring, u64>(entry, strings.strings.size()));
		strings.strings.push_back(std::move(entry));
	}
	if (strings.strings.size() == 0) strings.strings.push_back(std::wstring());
	else if (strings.strings[0].entry.size() == 0) strings.strings[0].entry = std::wstring();
	return exitFunc(true);
}

bool FileParser::WriteStrings(const DataStructure::StringsHolder& strings)
{
	Serializer sr;
	sr.Write(strings.availableSlots.size());
	for (u64 i = 0; i < strings.availableSlots.size(); i++)
	{
		sr.Write(strings.availableSlots[i]);
	}
	for (u64 i = 0; i < strings.strings.size(); i++)
	{
		sr.Write(strings.strings[i].entry.size());
		sr.Write(strings.strings[i].entry, false);
	}
	std::ofstream file(strFile, std::ios::binary | std::ios::trunc);
	if (file.fail())
	{
		file.close();
		return false;
	}
	file.write(reinterpret_cast<const char*>(sr.GetBuffer()), sr.GetBufferSize());
	file.close();
	return true;
}