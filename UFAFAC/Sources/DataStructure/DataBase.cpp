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
	auto fillSlot = [&](u32 slot) -> u32
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
		return slot;
	};
	if (!availableSlots.empty())
	{
		u32 result = fillSlot(availableSlots.front());
		std::copy(availableSlots.data() + 1, availableSlots.data() + availableSlots.size(), availableSlots.data());
		availableSlots.pop_back();
		return result;
	}
	datas.push_back(DataStructure::DataBaseEntry());
	return fillSlot(static_cast<u32>(datas.size() - 1));
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

std::vector<const DataBaseEntry*> DataStructure::DataBase::GetEntriesByTags(const std::vector<u32>& tagList, bool requireAllTags)
{
	std::vector<const DataBaseEntry*> result;
	for (auto& data : datas)
	{
		bool entryAdded = true;
		for (auto tag : tags.GetTagList(data.tags))
		{
			entryAdded = requireAllTags;
			for (auto id : tagList)
			{
				if (requireAllTags)
				{
					if (id != tag)
					{
						entryAdded = false;
						break;
					}
				}
				else
				{
					if (id == tag)
					{
						result.push_back(&data);
						entryAdded = true;
						break;
					}
				}
			}
			if (requireAllTags != entryAdded) break;
		}
		if (requireAllTags && entryAdded) result.push_back(&data);
	}
	return result;
}

void DataStructure::DataBase::SetEntryName(u32 entry, const std::wstring& name)
{
	assert(entry < datas.size());
	auto& e = datas[entry];
	strings.DecrementRef(e.name);
	e.name = strings.FindOrCreateString(name);
	strings.IncrementRef(e.name);
}

void DataStructure::DataBase::SetEntryAuthor(u32 entry, const std::wstring& name)
{
	assert(entry < datas.size());
	auto& e = datas[entry];
	strings.DecrementRef(e.authors);
	e.authors = strings.FindOrCreateString(name);
	strings.IncrementRef(e.authors);
}

void DataStructure::DataBase::SetEntryLocation(u32 entry, const std::wstring& name)
{
	assert(entry < datas.size());
	auto& e = datas[entry];
	strings.DecrementRef(e.location);
	e.location = strings.FindOrCreateString(name);
	strings.IncrementRef(e.location);
}

void DataStructure::DataBase::SetEntryEdition(u32 entry, const std::wstring& name)
{
	assert(entry < datas.size());
	auto& e = datas[entry];
	strings.DecrementRef(e.edition);
	e.edition = strings.FindOrCreateString(name);
	strings.IncrementRef(e.edition);
}

void DataStructure::DataBase::SetEntryDescrition(u32 entry, const std::wstring& name)
{
	assert(entry < datas.size());
	auto& e = datas[entry];
	strings.DecrementRef(e.description);
	e.description = strings.FindOrCreateString(name);
	strings.IncrementRef(e.description);
}

void DataStructure::DataBase::SetEntryTimeStamp(u32 entry, s64 timeStamp)
{
	assert(entry < datas.size());
	datas[entry].date = timeStamp;
}

void DataStructure::DataBase::SetEntryTags(u32 entry, const std::vector<u32>& tagList)
{
	assert(entry < datas.size());
	auto& e = datas[entry];
	tags.DecrementRef(e.tags);
	e.tags = tags.FindOrCreateTagList(tagList);
	tags.IncrementRef(e.tags);
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

wchar_t getRandomChar()
{
	int r = rand() * 27 / RAND_MAX;
	if (r == 26) return ' ';
	return r + 'a';
}
// TODO Remove

const std::wstring bufs[] =
{
	L"Amogus",
	L"Suspiscious",
	L"Crewmate",
	L"Sugoma",
	L"Sugomus",
	L"Ligma",
	L"Maween",
	L"Crashma",
	L"Creer",
	L"Skelon Musk",
	L"Seema Balls",
	L"E-TMA",
	L"Médo",
};

std::wstring generateString(u32 stringsize)
{
	if (rand() < RAND_MAX / 100)
	{
		return bufs[rand() % (sizeof(bufs) / sizeof(bufs[0]))];
	}
	std::wstring result;
	for (u32 i = 0; i < stringsize; i++)
	{
		if (i == 0 || result.back() == ' ') result.push_back(towupper(getRandomChar()));
		else result.push_back(getRandomChar());
	}
	return result;
}

void DataStructure::DataBase::CreateRandomEntries(u64 count)
{
	for (u64 i = 0; i < count; ++i)
	{
		u32 entry = PushEntry();
		SetEntryAuthor(entry, generateString(16));
		SetEntryName(entry, generateString(16));
		SetEntryDescrition(entry, generateString(128));
		SetEntryLocation(entry, generateString(32));
		SetEntryEdition(entry, generateString(16));
		SetEntryTimeStamp(entry, time(nullptr) + (rand() - RAND_MAX/2));
	}
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

void DataStructure::DataBase::ReferenceTags()
{
	for (auto& entry : datas)
	{
		tags.IncrementRef(entry.tags);
	}
}
