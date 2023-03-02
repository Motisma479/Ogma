#include "Utils.h"
#include <regex>
#include <algorithm>

std::wstring ToLower(std::wstring string)
{
	std::transform(
		string.begin(), string.end(),
		string.begin(),
		towlower);
	return string;
}

std::vector<std::wstring> Utils::GetFilesByName(const std::wstring& searchBoxText, const std::vector<std::wstring>& datas)
{
	std::wregex regexSearch(ToLower(searchBoxText));

	std::vector<std::wstring> out;

	for (const auto& str : datas) {
		if (std::regex_search(ToLower(str), regexSearch)) {
			out.push_back(str);
		}
	}
	return out;
}

std::string Utils::SystemStringToStdString(System::String^ string)
{
	char cStr[50] = { 0 };
	if (string->Length < sizeof(cStr))
		sprintf_s(cStr, "%s", string);
	return std::string(cStr);
}

void Utils::MarshalString(System::String^ s, std::wstring& os)
{
		using namespace System::Runtime::InteropServices;
		const wchar_t* chars =
			(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

