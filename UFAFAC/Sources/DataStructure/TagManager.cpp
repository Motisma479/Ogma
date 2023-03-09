#include "DataStructure/TagManager.hpp"
DataStructure::TagManager* DataStructure::TagManager::tagManager;

DataStructure::TagManager::TagManager()
{
}

DataStructure::TagManager::~TagManager()
{
}

void DataStructure::TagManager::Initialize()
{
	tagManager = new DataStructure::TagManager();
}

void DataStructure::TagManager::Delete()
{
	delete tagManager;
}

void DataStructure::TagManager::AddTag(const std::wstring& tag)
{
	this->tags.push_back(Tag(tag));
}

std::vector<Tag> DataStructure::TagManager::GetTags()
{
	return tags;
}
