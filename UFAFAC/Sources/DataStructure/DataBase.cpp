#include "DataStructure/DataBase.hpp"

#include <chrono>
#include <sstream>
#include <iostream>
#include "date.h"

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

u32 DataBase::PushEntry()
{
	return u32();
}

void DataBase::DeleteEntry(u32 index)
{

}

const DataBaseEntry& DataBase::GetEntryByIndex(u32 index)
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
	if (dateIn.year < -2000 || dateIn.year > 6000 || dateIn.month > 12 || dateIn.day > 31) return -1;
	std::stringstream timeStr; // = "01073-03-16T";
	timeStr << dateIn.year << "-" << (u32)dateIn.month << "-" << (u32)dateIn.day << "T";
	std::istringstream in{ timeStr.str() };
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::time_point(std::chrono::seconds(0x7fffffffffffffff));
	in >> date::parse("%8FT", tp);
	return std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch()).count();
}

Date DataStructure::DataBase::DateFromTimeStamp(s64 tmIn)
{
	std::chrono::time_point tp = std::chrono::system_clock::time_point(std::chrono::seconds(tmIn));
	auto k = std::chrono::duration_cast<date::days>(tp.time_since_epoch());
	date::year_month_day ymd = date::year_month_day(date::sys_days(k));
	Date result = {};
	result.year = (s32)ymd.year();
	result.month = (u32)ymd.month();
	result.day = (u32)ymd.day();
	return result;
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
