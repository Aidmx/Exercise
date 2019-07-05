#pragma once
#include <list>


class Circle
{
public:
	Circle()
	{ 
	}

	void a()
	{
		auto ite = mlist.begin();
		auto p = ite++;
		while (p != ite)
		{
			ite++;
			if (p == mlist.end())
			{
				// no circle
				break;
			}
		}
	}

	void b()
	{
		auto p1 = mlist.begin();
		auto p2 = p1;
		while (p1 != p2)
		{
			p1++;
			p2++;
			p2++;
			if (p2 == mlist.end())
			{
				// no circle
				break;
			}
		}
	}

	std::list<int> mlist;
};


