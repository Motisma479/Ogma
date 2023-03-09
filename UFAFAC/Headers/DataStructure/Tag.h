#pragma once
#include <string>
class Tag
{
public:
	Tag(const std::wstring& value) : name(value) {}

	std::wstring GetName() { return name; }
private:
	std::wstring name;
};