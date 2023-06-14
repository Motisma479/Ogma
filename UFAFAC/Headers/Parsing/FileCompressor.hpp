#include "Deserializer.hpp"
#include "Serializer.hpp"

namespace Parsing::FileCompressor
{
	// Returns true if everything goes right, path is the output file path
	bool CompressToFile(Serializer& sr, const std::wstring& path);

	// Returns true if everything goes right, path is the input file path, result can be fed to a deseralizer
	bool DecompressFromFile(std::vector<u8>& result, const std::wstring& path);
}