#pragma once

#include <vector>
#include <string>

#include "Core/Types.hpp"
#include "Tag.h"
#include "File.h"

namespace DataStructure
{
	class DataBaseEntry
	{
	public:
		DataBaseEntry() = default;

		~DataBaseEntry() = default;

		std::string name;
		std::string authors;
		std::string description;
		std::vector<Tag*> tags;
		int64_t date;
		std::vector<File*> files;
	private:
	};

}