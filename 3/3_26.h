#pragma once

#include <vector>

class CustomStack
{
public:
	CustomStack(const int pSize) : mSize(3 * pSize),
		mvecStack(3 * pSize), mBottom1Index(0),
		mBottom2Index(1),mBottom3Index(2)
	{
		//mStack = new int[mSize];
		mPush1Index = 0;
		mPush2Index = mPush1Index + 1;
		mPush3Index = mPush2Index + 1;
		mTop1Index = mPush1Index;
		mTop2Index = mPush2Index;
		mTop3Index = mPush3Index;
	}

	~CustomStack()
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
		mvecStack[mPush1Index] = pValue;
		mTop1Index = mPush1Index;
		mPush1Index += step;
		reserve(mPush1Index);
	}
	
	void push2(int pValue)
	{
		mvecStack[mPush2Index] = pValue;
		mTop2Index = mPush2Index;
		mPush2Index += step;
		reserve(mPush2Index);
	}

	void push3(int pValue)
	{
		mvecStack[mPush3Index] = pValue;
		mTop3Index = mPush3Index;
		mPush3Index += step;
		reserve(mPush3Index);
	}

	void pop1()
	{
		if (mTop1Index < mBottom1Index)
		{
			throw std::exception("error out of range.");
			return;
		}
		mTop1Index -= step;
		mPush1Index -= step;
	}

	void pop2()
	{
		if (mTop2Index < mBottom2Index)
		{
			throw std::exception("error out of range.");
			return;
		}
		mTop2Index -= step;
		mPush2Index -= step;
	}

	void pop3()
	{
		if (mTop3Index < mBottom3Index)
		{
			throw std::exception("error out of range.");
			return;
		}
		mTop3Index -= step;
		mPush3Index -= step;
	}
	bool empty1()
	{
		return mPush1Index == mBottom1Index;
	}
	bool empty2()
	{
		return mPush2Index == mBottom2Index;
	}
	bool empty3()
	{
		return mPush3Index == mBottom3Index;
	}


	static const int appendsize = 9;
private:
	static const int step = 3;
	std::vector<int> mvecStack;
	int mSize;
	int mPush1Index;
	int mPush2Index;
	int mPush3Index;
	int mTop1Index;
	int mTop2Index;
	int mTop3Index;
	const int mBottom1Index;
	const int mBottom2Index;
	const int mBottom3Index;
};
 
