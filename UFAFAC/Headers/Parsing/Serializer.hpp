#pragma once

#include <vector>
#include <string>

#include "Conversion.hpp"

namespace Parsing
{
	class Serializer
	{
	public:
		Serializer() = default;

		~Serializer() = default;

		const u8* GetBuffer() const { return buffer.data(); }
		const u64 GetBufferSize() const { return buffer.size(); }

		void Write(u8 in);
		void Write(s8 in);
		void Write(u16 in);
		void Write(s16 in);
		void Write(u32 in);
		void Write(s32 in);
		void Write(u64 in);
		void Write(s64 in);
		void Write(f32 in);
		void Write(f64 in);
		void Write(const u8* dataIn, u64 dataSize);
		void Write(const std::string& str, bool writeSize = true); // Size is written as 64 bits wide integer
		void Write(const std::wstring& str, bool writeSize = true); // Size is written as 64 bits wide integer
	private:
		std::vector<u8> buffer;
	};

}