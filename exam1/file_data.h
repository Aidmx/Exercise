#pragma once
#include  <stdio.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include "custom_stream.h"
#include "cmd_line.h"

using namespace  std;

#define HASHSIZE 1000003
#define  BUFFERCOUNT 1024

std::hash<string> gHash;

typedef struct InfoPair
{
	size_t mHashValue;
	string mKey;
	string mValue;

	explicit InfoPair()
	{

	}	
	explicit InfoPair(const InfoPair& pOther)
	{
		mHashValue = pOther.mHashValue;
		mKey = pOther.mKey;
		mValue = pOther.mValue;
	}

	explicit InfoPair(const string& pInfo)
	{
		std::string::size_type pos = pInfo.find(",") + 1;
		mKey = pInfo.substr(pos, 36);
		pos = pInfo.find(",", pos) + 1;
		const size_t len = pInfo.length() - pos - 2;
		mValue = pInfo.substr(pos, len);
		mHashValue = gHash(mKey);
	}

	bool operator==(const InfoPair& pOther) const
	{
		return (mHashValue == pOther.mHashValue)&&(mKey == pOther.mKey);
	}

	bool operator<(const InfoPair& pOther) const
	{
		return (mHashValue < pOther.mHashValue) || ((mHashValue == pOther.mHashValue)&&(mKey < pOther.mKey));
	}

	void Set(const InfoPair& pOther)
	{
		mHashValue = pOther.mHashValue;
		mKey = pOther.mKey;
		mValue = pOther.mValue;
	}

} InfoPair;


typedef vector<InfoPair> InfoPairsVector;
typedef vector<InfoPairsVector> InfoPairsHash;
typedef list<InfoPair>	InfoPairsList;
typedef set<InfoPair>	InfoPairsSet; 
typedef map<InfoPair, InfoPair>	InfoPairsMap;

class KeyFileData
{ 
public:
	KeyFileData(const char* pfileName, const char* pMode) : mStream(pfileName, pMode)
	{ 
	}

	~KeyFileData()
	{ 
	}
	

	bool Load(InfoPairsHash& pData)
	{
		if (mStream.isNull())
		{
			std::cout << " LoadData error : mStream  is null ." << std::endl;
			return false;
		}
		pData.resize(HASHSIZE);

		int lineNum = 0;
		//len = 36  
		char buffer[BUFFERCOUNT] = { 0 };
		//get title
		char* title = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
		if (title == nullptr)
		{
			return false;
		}
		bool  start = true;
		while (start)
		{ 
			memset(buffer, 0, BUFFERCOUNT);
			char* line = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
			if (line == nullptr)
			{
				start = false;
				break;
			}
			InfoPair pair(buffer);
			pData[pair.mHashValue % HASHSIZE].push_back(pair);
			lineNum++;
		}
		return true;
	}

	bool Load(InfoPairsList& pData)
	{
		if (mStream.isNull())
		{
			std::cout << " LoadData error : mStream  is null ." << std::endl;
			return false;
		}

		//len = 36  
		char buffer[BUFFERCOUNT] = { 0 };
		//get title
		char* title = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
		if (title == nullptr)
		{
			return false;
		}
		bool  start = true;
		while (start)
		{
			memset(buffer, 0, BUFFERCOUNT);
			char* line = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
			if (line == nullptr)
			{
				start = false;
				break;
			}
			InfoPair pair(buffer); 
			pData.push_back(pair);
		}
		return true;
	}

	bool Load(InfoPairsSet& pData)
	{
		if (mStream.isNull())
		{
			std::cout << " LoadData error : mStream  is null ." << std::endl;
			return false;
		}

		//len = 36  
		char buffer[BUFFERCOUNT] = { 0 };
		//get title
		char* title = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
		if (title == nullptr)
		{
			return false;
		}
		bool  start = true;
		while (start)
		{
			memset(buffer, 0, BUFFERCOUNT);
			char* line = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
			if (line == nullptr)
			{
				start = false;
				break;
			}
			InfoPair pair(buffer);
			pData.insert(pair);
		}
		return true;
	}

	bool Load(InfoPairsMap& pData)
	{
		if (mStream.isNull())
		{
			std::cout << " LoadData error : mStream  is null ." << std::endl;
			return false;
		}

		//len = 36  
		char buffer[BUFFERCOUNT] = { 0 };
		//get title
		char* title = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
		if (title == nullptr)
		{
			return false;
		}
		int lineNum = 0;
		bool  start = true;
		while (start)
		{
			memset(buffer, 0, BUFFERCOUNT);
			char* line = mStream.ReadLine(buffer, BUFFERCOUNT - 1);
			if (line == nullptr)
			{
				start = false;
				break;
			}

			InfoPair pair(buffer); 
			pData.insert(make_pair(pair.mKey, pair));
			lineNum++;
		}
		return true;
	}

public:
	CustomStream mStream;
};

class ToFileData
{
public:
	ToFileData(const char* pfileName, const char* pMode) : mStream(pfileName, pMode)
	{
		memset(mbuffer, 0, BUFFERCOUNT);
		mlineNum = 0;
		WriteTitle();
	}

	~ToFileData()
	{
	}


	void WriteLine(const InfoPairsHash& pKeyFileData, const InfoPair& pValueFileData )
	{
		for (auto ite_key = pKeyFileData[pValueFileData.mHashValue % HASHSIZE].begin();
			ite_key != pKeyFileData[pValueFileData.mHashValue% HASHSIZE].end(); ite_key++)
		{
			if (ite_key->mHashValue == pValueFileData.mHashValue)
			{
				Write(ite_key->mValue, pValueFileData.mValue);
			}
		}
	}

	void WriteLine(const InfoPairsList& pKeyFileData, const InfoPair& pValueFileData)
	{
		for (auto ite_key = pKeyFileData.begin(); ite_key != pKeyFileData.end(); ite_key++)
		{
			if (pValueFileData.mHashValue == ite_key->mHashValue)
			{
				Write(ite_key->mValue, pValueFileData.mValue);
			}
		}
	}

	void WriteLine(const InfoPairsSet& pKeyFileData, const InfoPair& pValueFileData)
	{
		auto ite_key = pKeyFileData.find(pValueFileData);
		if (ite_key != pKeyFileData.end())
			Write(ite_key->mValue, pValueFileData.mValue);
	}

	void WriteLine(const InfoPairsMap& pKeyFileData, const InfoPair& pValueFileData)
	{
		auto ite_key = pKeyFileData.find(pValueFileData);

		if (ite_key != pKeyFileData.end())
		{
			Write(ite_key->second.mValue, pValueFileData.mValue);
		}
	}

	void Write(const string& pKeyData, const string& pValueData)
	{
		mlineNum++;
		string line(std::to_string(mlineNum) + "," + pKeyData + "," + pValueData + '\n');
		memcpy_s(&mbuffer[0], BUFFERCOUNT, line.c_str(), line.size());
		mStream.WriteLine(line.c_str());
		memset(mbuffer, 0, BUFFERCOUNT);
	}

private:
	bool WriteTitle()
	{
		if (mStream.isNull())
		{
			std::cout << " WriteData error : mStream  is null ." << std::endl;
			return false;
		}
		char buffer[] = "No.,KEY,VALUE\n"; 
		if (EOF == mStream.WriteLine(buffer))
		{
			std::cout << " WriteData error : WriteLine  error ." << std::endl;
			return false;
		}
		mlineNum = 0;
		return true;
	}

public:
	char mbuffer[BUFFERCOUNT];
	CustomStream mStream; 
	int mlineNum;
};


class FromFileData
{
public:
	FromFileData(const char* pfileName, const char* pMode) : mStream(pfileName, pMode)
	{
		mLineNum = 0; 
		memset(mBuffer, 0, BUFFERCOUNT);
		//get title
		char* title = mStream.ReadLine(mBuffer, BUFFERCOUNT - 1);
	}

	~FromFileData()
	{
	}

	bool Load(InfoPair& pFromPair, int pLoadCount = 0)
	{
		if ((mStream.isNull()))
		{
			return false;
		}
		if ((pLoadCount > 0) && (mLineNum >= pLoadCount))
		{
			return false;
		}

		memset(mBuffer, 0, BUFFERCOUNT);
		char* line = mStream.ReadLine(mBuffer, BUFFERCOUNT - 1);
		if (line == nullptr)
		{
			return false;
		}
		InfoPair pair(mBuffer);
		pFromPair.Set(pair);
		mLineNum++;
		return true;
	}

public:
	CustomStream mStream;
	char mBuffer[BUFFERCOUNT];
	int mLineNum;
};
