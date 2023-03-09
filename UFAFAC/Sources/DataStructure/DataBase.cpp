#include "DataStructure/DataBase.hpp"

using namespace DataStructure;

DataBase* DataBase::dataBase;

void DataBase::Initialize()
{
	dataBase = new DataBase();
}

void DataBase::Delete()
{
	delete dataBase;
}

u64 DataBase::PushEntry()
{
	return u64();
}

const DataBaseEntry& DataBase::GetEntryByIndex(u64 index)
{
	return datas[index];
}

std::vector<const DataBaseEntry&> DataBase::GetEntriesByName(const std::wstring& name)
{
	std::vector<const DataBaseEntry&> result;
	std::wstring lower;
	for (auto& c : name)
	{
		if (c == towlower(c))
		{
			lower.push_back(c);
		}
	}
	for (auto& entry : datas)
	{
		if (strings.GetString(entry.name).find_first_of(lower) != std::wstring::npos) result.push_back(entry);
	}
	return result;
}

void DataStructure::DataBase::ReferenceStrings()
{
	for (auto& entry : datas)
	{
		strings.IncrementRef(entry.name);
		strings.IncrementRef(entry.authors);
		strings.IncrementRef(entry.description);
	}
}
