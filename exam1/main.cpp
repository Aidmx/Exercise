//add by allen

#pragma once
 
#include <stdio.h> 
#include <time.h>
#include <iostream>

#include "cmd_line.h"
#include "file_data.h"

using namespace  std;
template<typename TypeKey>
bool ProcessData(const CmdLine& pCmd, TypeKey& pKeyData);

int main(int argc, char* argv[])
{
	//∂¡»°csv 
	CmdLine cmd(argc, argv);
	if (!cmd.IsGetOpt())
	{
		return 0;
	}
	bool resutl = false;
	switch (cmd.Mode())
	{
	case MyMode::eVectorMode:
	{
		InfoPairsHash keydata;
		resutl = ProcessData(cmd, keydata);
	}
		break;
	case MyMode::eListMode:
	{
		InfoPairsList keydata;
		resutl = ProcessData(cmd, keydata);
	}
		break;
	case MyMode::eSetMode:
	{
		InfoPairsSet keydata;
		resutl = ProcessData(cmd, keydata);
	}
		break;
	case MyMode::eMapMode:
	{
		InfoPairsMap keydata;
		resutl = ProcessData(cmd, keydata);
	}
		break;
	default:
		break;
	}
	if (!resutl)
	{
		cout << "process data error" << endl;
	}
	clock_t end = clock();
	cout << "time used:" << ((double)end)/ CLOCKS_PER_SEC << endl;
	return 0;
}

template<typename TypeKey>
bool ProcessData(const CmdLine& pCmd, TypeKey& pKeyData)
{
	clock_t keytimeStart = clock();
	KeyFileData keyFile(pCmd.mKeyFileName.c_str(), "rb");
	if (!keyFile.Load(pKeyData))
	{
		return false;
	}
	clock_t keytimeEnd = clock();
	cout << "key time used:" << ((double)keytimeEnd - (double)keytimeStart) / CLOCKS_PER_SEC << endl;

	clock_t toFileTime = clock();
	FromFileData fromFile(pCmd.mFromFileName.c_str(), "rb"); 
	ToFileData toFile(pCmd.mToFileName.c_str(), "wb");
	InfoPair fromPair;
	while (fromFile.Load(fromPair, pCmd.mCount))
	{
		toFile.WriteLine(pKeyData, fromPair);
	}
	clock_t toFileEnd = clock();
	cout << "to file time used:" << ((double)toFileEnd - (double)toFileTime) / CLOCKS_PER_SEC << endl;
	return true;
}
