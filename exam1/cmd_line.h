#pragma once
#include <string>
#include <iostream>

using namespace  std;


typedef enum MyMode
{
	eVectorMode,
	eListMode,
	eSetMode,
	eMapMode
} MyMode;



class CmdLine
{
public:
	CmdLine(int argc, char* argv[])
	{
		mCount = 0;
		mMode = MyMode::eVectorMode;
		mOK = GetParam(argc, argv);
		if (!mOK)
		{
			cout << " cmd error" << endl; 
		}
	}
	bool IsGetOpt() { return mOK; };

	const MyMode& Mode() const { return mMode; }

private:
	bool GetParam(int argc, char* argv[])
	{
		//打开文件
		if (argc < 7)
		{
			return false;
		}
		const int last_index = argc - 1;
		bool foundKey = false, foundFrom = false, foundTo = false;
		for (int i = 0; i < argc; i++)
		{
			if ((0 == strcmp(argv[i], "-key")) && (i != last_index))
			{
				mKeyFileName = argv[i + 1];
				foundKey = true;
			}
			if ((0 == strcmp(argv[i], "-from")) && (i != last_index))
			{
				mFromFileName = argv[i + 1];
				foundFrom = true;
			}
			if (0 == strcmp(argv[i], "-to") && (i != last_index))
			{
				mToFileName = argv[i + 1];
				foundTo = true;
			}

			if (0 == strcmp(argv[i], "-mode") && (i != last_index))
			{ 
				if (0 == strcmp(argv[i + 1], "vector"))
				{
					mMode = MyMode::eVectorMode;
				}
				else if(0 == strcmp(argv[i + 1], "list"))
				{
					mMode = MyMode::eListMode;
				}
				else if (0 == strcmp(argv[i + 1], "set"))
				{
					mMode = MyMode::eSetMode;
				}
				else if (0 == strcmp(argv[i + 1], "map"))
				{
					mMode = MyMode::eMapMode;
				}
			}
			if (0 == strcmp(argv[i], "-cnt") && (i != last_index))
			{
				mCount = atoi(argv[i + 1]);
			}
		}

		if (!foundKey || !foundFrom || !foundTo)
		{
			return false;
		}
		return true; 
	}


public:
	string mKeyFileName;
	string mFromFileName;
	string mToFileName;
	int mCount;

private:
	MyMode mMode;
	bool mOK;
};
