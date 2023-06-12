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

u32 DataBase::CreateEntry()
{
	auto fillSlot = [&](u32 slot) -> u32
	{
		datas[slot] = DataBaseEntry();
		return slot;
	};
	if (!availableSlots.empty())
	{
		u32 result = fillSlot(availableSlots.back());
		availableSlots.pop_back();
		return result;
	}
	datas.push_back(DataBaseEntry());
	return fillSlot(static_cast<u32>(datas.size() - 1));
}

void DataBase::DeleteEntry(u32 index)
{
	assert(index < datas.size());
	for (auto& value : availableSlots)
	{
		if (value == index) return;
	}
	datas[index] = DataBaseEntry();
	availableSlots.push_back(index);
}

DataBaseEntry& DataBase::GetEntryByIndex(u32 index)
{
	return datas[index];
}

std::vector<u32> DataStructure::DataBase::GetEntries()
{
	std::vector<u32> out;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		bool found = false;
		for (u32 j = 0; j < availableSlots.size(); ++j)
		{
			if (availableSlots[j] == i)
			{
				found = true;
				break;
			}
		}
		if (found) continue;
		out.push_back(i);
	}
	return out;
}

std::vector<u32> DataBase::GetEntriesByName(const std::wstring& name)
{
	std::wregex regexSearch(Utils::ToLower(name));
	std::vector<u32> out;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		if (std::regex_search(Utils::ToLower(datas[i].name), regexSearch))
		{
			out.push_back(i);
		}
	}
	return out;
}

std::vector<u32> DataBase::GetEntriesByAuthor(const std::wstring& author)
{
	std::wregex regexSearch(Utils::ToLower(author));
	std::vector<u32> out;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		if (std::regex_search(Utils::ToLower(datas[i].authors), regexSearch))
		{
			out.push_back(i);
		}
	}
	return out;
}

std::vector<u32> DataBase::GetEntriesByLocation(const std::wstring& location)
{
	std::wregex regexSearch(Utils::ToLower(location));
	std::vector<u32> out;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		if (std::regex_search(Utils::ToLower(datas[i].location), regexSearch))
		{
			out.push_back(i);
		}
	}
	return out;
}

std::vector<u32> DataBase::GetEntriesByEdition(const std::wstring& edition)
{
	std::wregex regexSearch(Utils::ToLower(edition));
	std::vector<u32> out;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		if (std::regex_search(Utils::ToLower(datas[i].edition), regexSearch))
		{
			out.push_back(i);
		}
	}
	return out;
}

std::vector<u32> DataBase::GetEntriesByDescription(const std::wstring& desc)
{
	std::wregex regexSearch(Utils::ToLower(desc));
	std::vector<u32> out;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		if (std::regex_search(Utils::ToLower(datas[i].description), regexSearch))
		{
			out.push_back(i);
		}
	}
	return out;
}

std::vector<u32> DataBase::GetEntriesByTimeStamp(s64 lower, s64 upper)
{
	std::vector<u32> result;
	for (u32 i = 0; i < datas.size(); ++i)
	{
		if (datas[i].date >= lower && datas[i].date <= upper) result.push_back(i);
	}
	return result;
}

std::vector<u32> DataBase::GetEntriesByTags(const std::vector<u32>& tagList, bool requireAllTags)
{
	std::vector<u32> result;
	for (u32 i = 0; i < (u32)datas.size(); ++i)
	{
		bool entryAdded = false;
		for (u32 tag: datas[i].tags)
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
						result.push_back(i);
						entryAdded = true;
						break;
					}
				}
			}
			if (requireAllTags != entryAdded) break;
		}
		if (requireAllTags && entryAdded) result.push_back(i);
	}
	return result;
}

s64 DataBase::TimeStampFromDate(const Date& dateIn)
{
	if (dateIn.year < -2000 || dateIn.year > 6000 || dateIn.month > 12 || dateIn.day > 31) return -1;
	std::stringstream timeStr; // = "01073-03-16T";
	timeStr << dateIn.year << "-" << (u32)dateIn.month << "-" << (u32)dateIn.day << "T";
	std::istringstream in{ timeStr.str() };
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::time_point(std::chrono::seconds(0x7fffffffffffffff));
	in >> date::parse("%8FT", tp);
	return std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch()).count();
}

Date DataBase::DateFromTimeStamp(s64 tmIn)
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

void DataBase::OnDeleteTag(u32 index)
{
	for (auto& entry : datas)
	{
		for (s64 i = 0; i < entry.tags.size(); ++i)
		{
			if (entry.tags[i] == index)
			{
				std::copy(entry.tags.data() + (i + 1), entry.tags.data() + entry.tags.size(), entry.tags.data() + i);
				entry.tags.pop_back();
				--i;
			}
		}
	}
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
	L"Maween",
};

std::wstring generateString(u32 stringsize)
{
	if (rand() < RAND_MAX / 2)
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

void DataBase::CreateRandomEntries(u64 count)
{
	u32 max = (u32)tags.GetTags().size();
	for (u64 i = 0; i < count; ++i)
	{
		auto& entry = GetEntryByIndex(CreateEntry());
		entry.authors = generateString(16);
		entry.name = generateString(32);
		entry.description = generateString(256);
		entry.location = generateString(64);
		entry.edition = generateString(32);
		entry.date = time(nullptr) + (rand() - RAND_MAX/2);
		if (rand() < RAND_MAX / 2)
		{
			entry.files.push_back(L"C:\\Users\\Amogus\\Sussy_Stuff\\impostor_names.txt");
		}
		for (u32 j = 0; j < max; ++j)
		{
			if (rand() < RAND_MAX / 2) continue;
			entry.tags.push_back(j);
		}
	}
}

void DataBase::CreateRandomTags(u64 count)
{
	for (u64 i = 0; i < count; ++i)
	{
		tags.AddTag(generateString(16));
	}
}