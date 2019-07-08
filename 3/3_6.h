
//3.6 习题

#pragma once
#include <list>
#include <iostream>

//static int g_Index = 0;
//
//typedef struct Person
//{
//	int mNum;
//	Person()
//	{
//		mNum = ++g_Index;
//	}
//
//	bool operator==(const struct Person& pOther)const
//	{
//		return mNum == pOther.mNum;
//	}
//
//}Person;

class Questions_3_6
{
public:
	Questions_3_6()
	{ 
	}

	void Answer(int m, int n){
		std::list<int> persons;
		for (int i = 1; i <= n; i++)
		{
			persons.push_back(i);
		}

		auto ite = persons.begin();
		while (persons.size() > 1) {
			for (size_t step = m % persons.size(); step > 0; step--) {
				ite++;
				if (ite == persons.end())
				{
					ite = persons.begin();
				}
			}

			ite = persons.erase(ite);
			if (ite == persons.end())
			{
				ite = persons.begin();
			}

		}

		std::cout << "winner is: " << persons.front()/*.mNum */<< std::endl;
	}


	void AnswerBook(int m, int n)
	{
		using namespace std;
		int i, j,  mPrime, numLeft;
		list<int> L;
		numLeft = n;
		mPrime = m % n;
		for (i = 1; i <= n; i++)
			L.push_back(i);

		list<int>::iterator iter = L.begin();
		// Pass the potato
		for (i = 0; i < n; i++)
		{
			mPrime = mPrime % numLeft;
			if (mPrime <= numLeft / 2) // pass forward
			{
				for (j = 0; j < mPrime; j++)
				{
					iter++;
					if (iter == L.end())
						iter = L.begin();
				}
			}
			else // pass backward
			{
				for (j = 0; j < mPrime; j++)
				{
					if (iter == L.begin())
						iter = --L.end();
					else
						iter--;
				}
			}

			iter = L.erase(iter);
			if (iter == L.end())
				iter = L.begin();
			if (L.size() <= 1)
			{
				break;
			}
		}

		cout << "winner is: " << L.front()<< endl;
	}

};