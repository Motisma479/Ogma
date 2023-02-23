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

		u32 name;
		u32 authors;
		u32 description;
		u32 tags;
		s64 date;
		std::vector<File*> files;
	private:

	};

}