#pragma once

#include <string>
#include <vector>

#include "Core/Types.hpp"
#include "DataBaseEntry.hpp"

namespace Parsing
{
	class FileParser;
}

namespace DataStructure
{
	class DataBase
	{
	public:
		DataBase() = default;

		~DataBase() = default;

		u64 PushEntry();

	private:
		std::vector<DataBaseEntry> datas;

		friend Parsing::FileParser;
	};

}