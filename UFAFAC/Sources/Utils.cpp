#include "Utils.h"
#include <regex>

std::vector<std::wstring> Utils::GetFilesByName(const std::wstring& searchBoxText, const std::vector<std::wstring>& datas)
{
	// Construire l'expression régulière à partir de la chaîne de recherche
	std::wregex regexSearch(searchBoxText);

	std::vector<std::wstring> out;
	// Itérer sur le vecteur et chercher une correspondance avec l'expression régulière
	for (const auto& str : datas) {
		if (std::regex_search(str, regexSearch)) {
			out.push_back(str);
		}
	}
	// Aucune correspondance n'a été trouvée, retourner faux
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

