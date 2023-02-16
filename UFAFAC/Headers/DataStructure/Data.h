#pragma once
#include <string>
#include <vector>
#include "Tag.h"
#include "File.h"

class Data
{
private:
	std::string name;
	std::vector<std::string> authors;
	std::string description;
	std::vector<Tag*> tags;
	int64_t date;
	std::vector<File*> files;

public:
};