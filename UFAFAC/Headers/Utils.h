#pragma once
#include <vector>
#include <string>
namespace Utils {
	std::wstring ToLower(std::wstring string);
	std::vector<std::wstring> GetFilesByName(const std::wstring& searchBoxText, const std::vector<std::wstring>& datas);
	std::wstring SystemStringToStdWString(System::String^ string);
	System::String^ StdWStringToSystemString(const std::wstring& string);

	void MarshalString(System::String^ s, std::wstring& os);
}