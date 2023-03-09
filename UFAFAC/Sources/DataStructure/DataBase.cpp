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

const DataBaseEntry& DataBase::GetEntryByName(const std::wstring& name)
{
	u64 index = -1;
	// TODO: insérer une instruction return ici
	return datas[index];
}
