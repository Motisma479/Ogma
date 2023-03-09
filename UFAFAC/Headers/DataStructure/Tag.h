#pragma once
#include <string>
class Tag
{
public:
	Tag(const std::wstring& value) : name(value) {}
private:
	std::wstring name;
};