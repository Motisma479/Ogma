#include "DataStructure/DataBase.hpp"
DataStructure::DataBase* DataStructure::DataBase::dataBase;

void DataStructure::DataBase::Initialize()
{
	dataBase = new DataBase();
}

void DataStructure::DataBase::Delete()
{
	delete dataBase;
}
