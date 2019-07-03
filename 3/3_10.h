#pragma once

#include <algorithm>


template<typename Object>
class Vector
{
public:
	explicit  Vector(int pInitSize) : theSize{ pInitSize },
		theCapacity{ initSize + SPARE_CAPACITY }
	{
		objects = new Object[theCapacity];
	}
	 
	Vector(Vector&& rhs) : theSize{ rhs.theSize },
		theCapactiy{ rhs.theCapactiy },
		objects{ rhs.objects }
	{
		rhs.theSize = 0;
		rhs.theCapactiy = 0;
		rhs.objects = nullptr;
	}
	
	~Vector()
	{
		delete[] objects;
	};

	Vector& operator=(const Vector& rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}


	Vector& operate= (Vector&& rhs) 
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapactiy, rhs.theCapactiy);
		std::swap(objects, rhs.objects);
		return *this;
	}


	static  const int SPARE_CAPACITY = 16;
private:
	int theSize;
	int theCapactiy;
	Object* objects;
};


template<typename Object>
class Iterator
{




};


