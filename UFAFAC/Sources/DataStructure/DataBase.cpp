#include "DataStructure/DataBase.hpp"

#include <chrono>
#include <sstream>
#include <iostream>
#include <regex>
#include "date.h"
#include "Utils.h"

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
	auto fillSLot = [&](u32 slot) -> void
	{
		datas[slot] = DataBaseEntry();
		u32 str = strings.FindOrCreateString(std::wstring(L""));
		datas[slot].name = str;
		datas[slot].authors = str;
		datas[slot].description = str;
		datas[slot].edition = str;
		datas[slot].location = str;
		strings.IncrementRef(str);
		strings.IncrementRef(str);
		strings.IncrementRef(str);
		strings.IncrementRef(str);
		strings.IncrementRef(str);
	};
	if (!availableSlots.empty())
	{
		u32 slot = availableSlots.front();
		datas[slot] = DataBaseEntry();
		u32 str = strings.FindOrCreateString(std::wstring(L""));
		datas[slot].name = str;
		datas[slot].authors = str;
		datas[slot].description = str;
		strings.IncrementRef(str);
		strings.IncrementRef(str);
		strings.IncrementRef(str);
		std::copy(availableSlots.data() + 1, availableSlots.data() + availableSlots.size(), availableSlots.data());
		availableSlots.pop_back();
		return slot;
	}
	return u32();
}

void DataBase::DeleteEntry(u32 index)
{
	assert(index < datas.size());
	for (auto& value : availableSlots)
	{
		if (value == index) return;
	}
	availableSlots.push_back(index);
}

const DataBaseEntry& DataBase::GetEntryByIndex(u32 index)
{
	return datas[index];
}

std::vector<const DataBaseEntry*> DataBase::GetEntriesByName(const std::wstring& name)
{
	std::wregex regexSearch(Utils::ToLower(name));
	std::vector<const DataBaseEntry*> out;
	for (const auto& str : datas)
	{
		if (std::regex_search(Utils::ToLower(strings.GetString(str.name)), regexSearch))
		{
			out.push_back(&str);
		}
	}
	return out;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByAuthor(const std::wstring& author)
{
	std::wregex regexSearch(Utils::ToLower(author));
	std::vector<const DataBaseEntry*> out;
	for (const auto& str : datas)
	{
		if (std::regex_search(Utils::ToLower(strings.GetString(str.authors)), regexSearch))
		{
			out.push_back(&str);
		}
	}
	return out;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByLocation(const std::wstring& location)
{
	std::wregex regexSearch(Utils::ToLower(location));
	std::vector<const DataBaseEntry*> out;
	for (const auto& str : datas)
	{
		if (std::regex_search(Utils::ToLower(strings.GetString(str.location)), regexSearch))
		{
			out.push_back(&str);
		}
	}
	return out;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByEdition(const std::wstring& edition)
{
	std::wregex regexSearch(Utils::ToLower(edition));
	std::vector<const DataBaseEntry*> out;
	for (const auto& str : datas)
	{
		if (std::regex_search(Utils::ToLower(strings.GetString(str.edition)), regexSearch))
		{
			out.push_back(&str);
		}
	}
	return out;
}

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByDescription(const std::wstring& desc)
{
	std::wregex regexSearch(Utils::ToLower(desc));
	std::vector<const DataBaseEntry*> out;
	for (const auto& str : datas)
	{
		if (std::regex_search(Utils::ToLower(strings.GetString(str.description)), regexSearch))
		{
			out.push_back(&str);
		}
	}
	return out;
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

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByTags(const std::vector<u32>& tagList)
{
	std::vector<const DataBaseEntry*> result;
	for (auto& data : datas)
	{
		for (auto tag : tags.GetTagList(data.tags))
		{
			bool entryAdded = false;
			for (auto id : tagList)
			{
				if (id == tag)
				{
					result.push_back(&data);
					entryAdded = true;
					break;
				}
			}
			if (entryAdded) break;
		}
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
		result.push_back(towlower(c));
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
