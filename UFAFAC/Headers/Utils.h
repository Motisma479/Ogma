#pragma once
#include <vector>
#include <string>
namespace Utils {
	std::vector<std::wstring> GetFilesByName(const std::wstring& searchBoxText, const std::vector<std::wstring>& datas);
	std::string SystemStringToStdString(System::String^ string);

	void MarshalString(System::String^ s, std::wstring& os);
}