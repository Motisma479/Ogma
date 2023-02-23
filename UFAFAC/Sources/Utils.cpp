#include "Utils.h"
#include <regex>

std::vector<std::string> Utils::GetFilesByName(const std::string& searchBoxText, const std::vector<std::string>& datas)
{
	// Construire l'expression régulière à partir de la chaîne de recherche
	std::regex regexSearch(searchBoxText);

	std::vector<std::string> out;
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

