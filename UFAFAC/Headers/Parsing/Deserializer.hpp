#pragma once

#include <vector>
#include <string>

#include "Conversion.hpp"

namespace Parsing
{
	class Deserializer
	{
	public:
		Deserializer(const u8* data, u64 dataSize) : buffer(data), bufferSize(dataSize) {}
		Deserializer(const std::vector<u8>& data) : Deserializer(data.data(), data.size()) {}

		~Deserializer() = default;

		const u64 CursorPos() const { return cPos; }
		const u64 BufferSize() const { return bufferSize; }

		bool Read(u8& in);
		bool Read(s8& in);
		bool Read(u16& in);
		bool Read(s16& in);
		bool Read(u32& in);
		bool Read(s32& in);
		bool Read(u64& in);
		bool Read(s64& in);
		bool Read(f32& in);
		bool Read(f64& in);
		bool Read(u8* dataIn, u64 dataSize);
		bool Read(std::string& str, u64 strSize);
		bool Read(std::string& str); // Size is	assumed to be 64 bits wide
		bool Read(std::wstring& str, u64 strSize);
		bool Read(std::wstring& str); // Size is assumed to be 64 bits wide
		bool Read(std::vector<u32>& vec, u64 strSize);
		bool Read(std::vector<u32>& vec); // Size is assumed to be 64 bits wide
	private:
		const u8* buffer;
		const u64 bufferSize;
		u64 cPos = 0;
	};

}