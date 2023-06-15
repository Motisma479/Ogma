#include "Parsing/FileCompressor.hpp"

#include <Windows.h>
#include <compressapi.h>

using namespace Parsing;

bool FileCompressor::CompressToFile(Serializer& sr, const std::wstring& path)
{
    COMPRESSOR_HANDLE Compressor = NULL;
    PBYTE CompressedBuffer = NULL;
    BOOL Success;
    HANDLE CompressedFile = INVALID_HANDLE_VALUE;
    SIZE_T CompressedDataSize, CompressedBufferSize;
    DWORD ByteWritten;

    auto ClearData = [&](bool noDeleteFile) -> bool
    {
        if (Compressor != NULL)
        {
            CloseCompressor(Compressor);
        }
        if (CompressedBuffer)
        {
            free(CompressedBuffer);
        }
        if (CompressedFile != INVALID_HANDLE_VALUE)
        {
            if (!noDeleteFile)
            {
                FILE_DISPOSITION_INFO fdi;
                fdi.DeleteFile = TRUE;
                Success = SetFileInformationByHandle(CompressedFile, FileDispositionInfo, &fdi, sizeof(FILE_DISPOSITION_INFO));
                if (!Success)
                {
                    wprintf(L"Cannot delete corrupted compressed file.\n");
                }
            }
            CloseHandle(CompressedFile);
        }
        return noDeleteFile;
    };

    CompressedFile = CreateFile(path.c_str(), GENERIC_WRITE | DELETE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (CompressedFile == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Cannot create file \t%s\n", path.c_str());
        return ClearData(false);
    }

    Success = CreateCompressor(COMPRESS_ALGORITHM_MSZIP, NULL, &Compressor);
    if (!Success)
    {
        wprintf(L"Cannot create a compressor %d.\n", GetLastError());
        return ClearData(false);
    }

    Success = Compress(Compressor, sr.GetBuffer(), sr.GetBufferSize(), NULL, 0, &CompressedBufferSize);
    if (!Success)
    {
        DWORD ErrorCode = GetLastError();

        if (ErrorCode != ERROR_INSUFFICIENT_BUFFER)
        {
            wprintf(L"Cannot compress data: %d.\n", ErrorCode);
            return ClearData(false);
        }

        CompressedBuffer = (PBYTE)malloc(CompressedBufferSize);
        if (!CompressedBuffer)
        {
            wprintf(L"Cannot allocate memory for compressed buffer.\n");
            return ClearData(false);
        }
    }

    Success = Compress(Compressor, sr.GetBuffer(), sr.GetBufferSize(), CompressedBuffer, CompressedBufferSize, &CompressedDataSize);
    if (!Success)
    {
        wprintf(L"Cannot compress data: %d\n", GetLastError());
        return ClearData(false);
    }

    Success = WriteFile(CompressedFile, CompressedBuffer, (DWORD)CompressedDataSize, &ByteWritten, NULL);
    if ((ByteWritten != CompressedDataSize) || (!Success))
    {
        wprintf(L"Cannot write compressed data to file: %d.\n", GetLastError());
        return ClearData(false);
    }

	return ClearData(true);
}

bool Parsing::FileCompressor::DecompressFromFile(std::vector<u8>& result, const std::wstring& path)
{
    DECOMPRESSOR_HANDLE Decompressor = NULL;
    PBYTE CompressedBuffer = NULL;
    HANDLE InputFile = INVALID_HANDLE_VALUE;
    BOOL Success;
    SIZE_T DecompressedBufferSize, DecompressedDataSize;
    DWORD InputFileSize, ByteRead;
    LARGE_INTEGER FileSize;

    auto ClearData = [&](bool isValid)
    {
        if (Decompressor != NULL)
        {
            CloseDecompressor(Decompressor);
        }
        if (CompressedBuffer)
        {
            free(CompressedBuffer);
        }
        if (InputFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(InputFile);
        }
        return isValid;
    };

    InputFile = CreateFile(path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (InputFile == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Cannot open \t%s\n", path.c_str());
        return ClearData(false);
    }

    Success = GetFileSizeEx(InputFile, &FileSize);
    if (!Success || FileSize.QuadPart > 0xffffffff) // Can we easily read a file larger than that ?
    {
        wprintf(L"Cannot get input file size, or size is larger than 4GB.\n");
        return ClearData(false);
    }
    InputFileSize = FileSize.LowPart;

    CompressedBuffer = (PBYTE)malloc(InputFileSize);
    if (!CompressedBuffer)
    {
        wprintf(L"Cannot allocate memory for compressed buffer.\n");
        return ClearData(false);
    }

    Success = ReadFile(InputFile, CompressedBuffer, InputFileSize, &ByteRead, NULL);
    if ((!Success) || (ByteRead != InputFileSize))
    {
        wprintf(L"Cannot read from \t%s\n", path.c_str());
        return ClearData(false);
    }

    Success = CreateDecompressor( COMPRESS_ALGORITHM_MSZIP, NULL, &Decompressor);
    if (!Success)
    {
        wprintf(L"Cannot create a decompressor: %d.\n", GetLastError());
        return ClearData(false);
    }

    Success = Decompress(Decompressor, CompressedBuffer, InputFileSize, NULL, 0, &DecompressedBufferSize);
    if (!Success)
    {
        DWORD ErrorCode = GetLastError();

        // Note that the original size returned by the function is extracted 
        // from the buffer itself and should be treated as untrusted and tested
        // against reasonable limits.
        if (ErrorCode != ERROR_INSUFFICIENT_BUFFER)
        {
            wprintf(L"Cannot decompress data: %d.\n", ErrorCode);
            return ClearData(false);
        }
        result.resize(DecompressedBufferSize);
    }

    Success = Decompress(Decompressor, CompressedBuffer, InputFileSize, result.data(), DecompressedBufferSize, &DecompressedDataSize);
    if (!Success)
    {
        wprintf(L"Cannot decompress data: %d.\n", GetLastError());
        return ClearData(false);
    }

	return ClearData(true);
}