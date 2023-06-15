#include "Parsing/Deserializer.hpp"

using namespace Parsing;

bool Deserializer::Read(u8& in)
{
	if (cPos >= bufferSize) return false;
	in = buffer[cPos++];
	return true;
}

bool Deserializer::Read(s8& in)
{
	return Read(reinterpret_cast<u8&>(in));
}

bool Deserializer::Read(u16& in)
{
	u16 tmp = 0;
	if (cPos + sizeof(tmp) > bufferSize) return false;
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		tmp |= (u64)buffer[cPos++] << (i*8);
	}
	Conversion::ToLocal(tmp, in);
	return true;
}

bool Deserializer::Read(s16& in)
{
	return Read(reinterpret_cast<u16&>(in));
}

bool Deserializer::Read(u32& in)
{
	u32 tmp = 0;
	if (cPos + sizeof(tmp) > bufferSize) return false;
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		tmp |= (u64)buffer[cPos++] << (i * 8);
	}
	Conversion::ToLocal(tmp, in);
	return true;
}

bool Deserializer::Read(s32& in)
{
	return Read(reinterpret_cast<u32&>(in));
}

bool Deserializer::Read(u64& in)
{
	u64 tmp = 0;
	if (cPos + sizeof(tmp) > bufferSize) return false;
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		tmp |= (u64)buffer[cPos++] << (i * 8);
	}
	Conversion::ToLocal(tmp, in);
	return true;
}

bool Deserializer::Read(s64& in)
{
	return Read(reinterpret_cast<u64&>(in));
}

bool Deserializer::Read(f32& in)
{
	u32 tmp = 0;
	if (cPos + sizeof(tmp) > bufferSize) return false;
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		tmp |= (u64)buffer[cPos++] << (i * 8);
	}
	Conversion::ToLocal(tmp, in);
	return true;
}

bool Deserializer::Read(f64& in)
{
	u64 tmp = 0;
	if (cPos + sizeof(tmp) > bufferSize) return false;
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		tmp |= (u64)buffer[cPos++] << (i * 8);
	}
	Conversion::ToLocal(tmp, in);
	return true;
}

bool Deserializer::Read(u8* dataIn, u64 dataSize)
{
	if (cPos + dataSize > bufferSize) return false;
	std::copy(buffer + cPos, buffer + (cPos + dataSize), dataIn);
	cPos += dataSize;
	return true;
}

bool Deserializer::Read(std::string& str, u64 strSize)
{
	str.resize(strSize);
	if (!strSize) return true;
	else if (strSize + cPos > bufferSize) return false;
	return Read(reinterpret_cast<u8*>(str.data()), strSize);
}

bool Deserializer::Read(std::string& str)
{
	u64 size;
	return (Read(size) && (size + cPos <= bufferSize) && Read(str, size));
}

bool Deserializer::Read(std::wstring& str, u64 strSize)
{
	str.resize(strSize);
	if (!strSize) return true;

	if (cPos + strSize*sizeof(wchar_t) > bufferSize) return false;
	u16 c; // TODO change for later
	for (u64 i = 0; i < strSize; i++)
	{
		Read(c);
		str[i] = c;
	}
	return true;
}

bool Deserializer::Read(std::wstring& str)
{
	u64 size;
	return (Read(size) && (size * sizeof(wchar_t) + cPos <= bufferSize) && Read(str, size));
}

bool Deserializer::Read(std::vector<u32>& vec, u64 strSize)
{
	vec.resize(strSize);
	if (!strSize) return true;

	if (cPos + strSize * sizeof(u32) > bufferSize) return false;
	u32 val;
	for (u64 i = 0; i < strSize; i++)
	{
		Read(val);
		vec[i] = val;
	}
	return true;
}

bool Deserializer::Read(std::vector<u32>& vec)
{
	u64 size;
	return (Read(size) && (size * sizeof(u32) + cPos <= bufferSize) && Read(vec, size));
}