#pragma once

#include <vector>

class CostomStack
{
public:
	CostomStack(const int pSize) : mSize(3 * pSize),
		mvecStack(3 * pSize), mBottom1Index(0),
		mBottom2Index(1),mBottom3Index(2)
	{
		//mStack = new int[mSize];
		mTop1Index = 0;
		mTop2Index = mTop1Index + 1;
		mTop3Index = mTop2Index + 1;
	}

	~CostomStack()
	{
	}

	void reserve(int pIndex)
	{
		if (pIndex >= mSize)
		{
			mSize = appendsize * 3 + mSize;
			mvecStack.reserve(mSize);
			for (int i = pIndex; i < mSize; i++)
				mvecStack.push_back(0);
		}
	}

	int top1() const { return mvecStack[mTop1Index]; }
	int top2() const { return mvecStack[mTop2Index]; }
	int top3() const { return mvecStack[mTop3Index]; }

	void push1(int pValue)
	{
		mTop1Index += step;
		reserve(mTop1Index);
		mvecStack[mTop1Index] = pValue;
	}
	void push2(int pValue)
	{
		mTop2Index += step;
		reserve(mTop1Index);
		mvecStack[mTop1Index] = pValue;
	}
	void push3(int pValue)
	{
		mTop3Index += step;
		reserve(mTop1Index);
		mvecStack[mTop1Index] = pValue;
	}

	void pop1()
	{
		if (mTop1Index <= mBottom1Index)
		{
			throw std::exception("error out of range.");
			return;
		}
		mTop1Index -= step;
	}

	void pop2()
	{
		if (mTop2Index <= mBottom2Index)
		{
			throw std::exception("error out of range.");
			return;
		}
		mTop2Index -= step;
	}

	void pop3()
	{
		if (mTop3Index <= mBottom3Index)
		{
			throw std::exception("error out of range.");
			return;
		}
		mTop3Index -= step;
	}
	static const int appendsize = 9;
private:
	static const int step = 3;
	//int* mStack;
	std::vector<int> mvecStack;
	int mSize;
	int mTop1Index;
	int mTop2Index;
	int mTop3Index;
	const int mBottom1Index;
	const int mBottom2Index;
	const int mBottom3Index;
};
 
