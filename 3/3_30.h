#pragma once
#include <list>
#include <vector>


//self-adjusting list
//前端插入，
//find 当一个元素被find 则移到表的前端但不改变其余的项的相对顺序

class SelfAdjustTable
{
public:
	SelfAdjustTable()
	{
		
	}
	//a
	void VectorPushFront(const int pValue)
	{
		mVec.insert(mVec.begin(), pValue);
	}

	void VectorFind(const int pValue)
	{
		for (auto found = mVec.begin(); found != mVec.end(); ++found)
		{
			if (pValue == *found)
			{  
				mVec.erase(found);
				VectorPushFront(pValue);
				break;
			}
		}

	}
	//b
	void ListPushFront(const int pValue)
	{
		mList.push_front(pValue);
	}


	void ListFind(const int pValue)
	{
		for (auto found = mList.begin(); found != mList.end();++found)
		{
			if (*found == pValue)
			{
				mList.erase(found);
				mList.push_front(pValue);
				break;
			}
		} 
	}
	 
private:
	std::list<int> mList;
	std::vector<int> mVec;
};
