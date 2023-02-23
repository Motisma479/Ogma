#pragma once
#include <vector>
#include <string>
namespace Utils {
	std::vector<std::string> GetFilesByName(const std::string& searchBoxText, const std::vector<std::string>& datas);
	std::string SystemStringToStdString(System::String^ string);
}