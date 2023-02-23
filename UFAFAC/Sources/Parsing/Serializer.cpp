#include "Parsing/Serializer.hpp"

using namespace Parsing;

void Serializer::Write(u8 in)
{
	buffer.push_back(in);
}

void Serializer::Write(s8 in)
{
	buffer.push_back(static_cast<u8>(in));
}

void Serializer::Write(u16 in)
{
	u16 tmp;
	Conversion::ToNetwork(in, tmp);
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		buffer.push_back((tmp >> (i*8) & 0xff));
	}
}

void Serializer::Write(s16 in)
{
	Write(static_cast<u16>(in));
}

void Serializer::Write(u32 in)
{
	u32 tmp;
	Conversion::ToNetwork(in, tmp);
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		buffer.push_back((tmp >> (i * 8) & 0xff));
	}
}

void Serializer::Write(s32 in)
{
	Write(static_cast<u32>(in));
}

void Serializer::Write(u64 in)
{
	u64 tmp;
	Conversion::ToNetwork(in, tmp);
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		buffer.push_back((tmp >> (i * 8) & 0xff));
	}
}

void Serializer::Write(s64 in)
{
	Write(static_cast<u64>(in));
}

void Serializer::Write(f32 in)
{
	u32 tmp;
	Conversion::ToNetwork(in, tmp);
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		buffer.push_back((tmp >> (i * 8) & 0xff));
	}
}

void Serializer::Write(f64 in)
{
	u64 tmp;
	Conversion::ToNetwork(in, tmp);
	for (u8 i = 0; i < sizeof(tmp); i++)
	{
		buffer.push_back((tmp >> (i * 8) & 0xff));
	}
}

void Serializer::Write(const u8* dataIn, u64 dataSize)
{
	buffer.resize(buffer.size() + dataSize);
	std::copy(dataIn, dataIn + dataSize, buffer.data() + (buffer.size() - dataSize));
}

void Serializer::Write(const std::string& str, bool writeSize)
{
	if (writeSize) Write(str.size());
	Write(reinterpret_cast<const u8*>(str.c_str()), str.size());
}

void Serializer::Write(const std::wstring& str, bool writeSize)
{
	if (writeSize) Write(str.size());
	u16 c; // TODO change for later
	for (u64 i = 0; i < str.size(); i++)
	{
		c = str[i];
		Write(c); 
	}
}
