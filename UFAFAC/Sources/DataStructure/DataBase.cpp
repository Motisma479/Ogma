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

std::vector<const DataBaseEntry*> DataBase::GetEntriesByName(const std::wstring& name)
{
	std::vector<const DataBaseEntry*> result;
	std::wstring lower = ToLower(name);
	for (auto& entry : datas)
	{
		if (strings.GetString(entry.name).find_first_of(lower) != std::wstring::npos) result.push_back(&entry);
	}
	return result;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByAuthor(const std::wstring& author)
{
	std::vector<const DataBaseEntry*> result;
	std::wstring lower = ToLower(author);
	for (auto& entry : datas)
	{
		if (strings.GetString(entry.authors).find_first_of(lower) != std::wstring::npos) result.push_back(&entry);
	}
	return result;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByDescription(const std::wstring& desc)
{
	std::vector<const DataBaseEntry*> result;
	std::wstring lower = ToLower(desc);
	for (auto& entry : datas)
	{
		if (strings.GetString(entry.description).find_first_of(lower) != std::wstring::npos) result.push_back(&entry);
	}
	return result;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByTimeStamp(s64 lower, s64 upper)
{
	std::vector<const DataBaseEntry*> result;
	for (auto& entry : datas)
	{
		if (entry.date >= lower && entry.date <= upper) result.push_back(&entry);
	}
	return result;
}

s64 DataStructure::DataBase::TimeStampFromDate(const Date& dateIn)
{
	// TODO
	return s64();
}

Date DataStructure::DataBase::DateFromTimeStamp(s64 tmIn)
{
	// TODO
	return Date();
}

std::wstring DataBase::ToLower(const std::wstring& in)
{
	std::wstring result;
	for (auto& c : in)
	{
		if (c == towlower(c))
		{
			result.push_back(c);
		}
	}
	return result;
}

void DataBase::ReferenceStrings()
{
	for (auto& entry : datas)
	{
		strings.IncrementRef(entry.name);
		strings.IncrementRef(entry.authors);
		strings.IncrementRef(entry.description);
	}
}
