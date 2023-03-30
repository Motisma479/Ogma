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

		u32 name = -1;
		u32 authors = -1;
		u32 edition = -1;
		u32 description = -1;
		u32 location = -1;
		u32 tags = -1;
		s64 date = -1;
		std::vector<File*> files;
	private:

	};

}