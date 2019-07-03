#pragma once
#include <cerrno>
#include <stdio.h>
#include <iostream>


class CustomStream
{
public:
	CustomStream(const char* pfileName ,const char* pMode)
	{ 
		errno_t err = Open( pfileName, pMode);
		if (err != 0)
		{
			std::cout << " fopen_s error : filename:" << pfileName << std::endl;
		}

	}
	
	~CustomStream()
	{
		Close();
	}

	 
	errno_t Open(char const* pFileName, char const* pMode)
	{
		return ::fopen_s(&mFile, pFileName, pMode);
	}
	 
	void Close()
	{
		if (nullptr != mFile) {
			::fclose(mFile);
			mFile = nullptr;
		}
	} 
	char* ReadLine(char* pBuffer, int pMaxCount) const
	{
		if ((mFile == nullptr) && (nullptr == pBuffer)) {
			return nullptr;
		}
		return fgets(pBuffer, pMaxCount, mFile);
	}

	int WriteLine(const char* pBuffer) const
	{
		if ((mFile == nullptr) && (nullptr == pBuffer)) {
			return 0;
		}
		return fputs(pBuffer, mFile);
	}

	bool isNull() const { return mFile == nullptr; }

private: 
	FILE* mFile;
};
