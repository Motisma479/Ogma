#pragma once

#include <vector>
#include <string>

#include "Core/Types.hpp"
#include "Tag.h"

namespace DataStructure
{
	class DataBaseEntry
	{
	public:
		DataBaseEntry() = default;

		~DataBaseEntry() = default;

		std::wstring name = L"Nouveau Document";
		std::wstring authors = L"";
		std::wstring edition = L"";
		std::wstring description = L"";
		std::wstring location = L"";
		std::vector<u32> tags = {};
		s64 date = -1;
		std::vector<std::wstring> files;
	private:

	};

}