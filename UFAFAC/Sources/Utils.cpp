#include "Utils.h"
#include <regex>
#include <algorithm>

std::wstring Utils::ToLower(std::wstring string)
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

std::wstring Utils::SystemStringToStdWString(System::String^ string)
{
	System::String^ text = string;
	System::Runtime::InteropServices::Marshal::StringToCoTaskMemUni(text);
	auto wtext = std::wstring();
	Utils::MarshalString(text, wtext);
	return wtext;
}

System::String^ Utils::StdWStringToSystemString(const std::wstring& string)
{
	return System::Runtime::InteropServices::Marshal::PtrToStringUni(System::IntPtr((void*)string.c_str()));
}

void Utils::MarshalString(System::String^ s, std::wstring& os)
{
		using namespace System::Runtime::InteropServices;
		const wchar_t* chars =
			(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

