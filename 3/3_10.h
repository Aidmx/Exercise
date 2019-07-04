#pragma once

#include <algorithm>

namespace allen
{ 
	template<typename Object>
	class Vector;

	template<typename Object>
	class VectorIterator
	{
	public:
		//explicit VectorIterator() :mPtr{nullptr}
		//{
		//}
		//explicit VectorIterator(const Object& pObeject) :mPtr{ &pObeject }
		//{ 
		//}	
		VectorIterator() :mPtr(nullptr)
		{

		}

		explicit VectorIterator(Object* pCurrent)
			:mPtr(pCurrent)
		{

		}

		void operator=(Object* pObject) const
		{
			mPtr = pObject;
		}
		void operator=(VectorIterator<Object>* pOther) const
		{
			mPtr = pOther->mPtr;
		}
		Object& operator*() const
		{
			return *mPtr;
		}

		bool operator== (const VectorIterator& pOther) const
		{
			return mPtr == pOther.mPtr;
		}

		bool operator!= (const VectorIterator& pOther) const
		{
			return !(*this == pOther);
		}

		VectorIterator& operator++() {
			mPtr++;
			return *this;
		}
		//后++
		VectorIterator& operator++(int) {
			VectorIterator old = *this;
			++(*this);
			return old;
		}
		//VectorIterator& operator--() {
		//	--*(Object*)mPtr;
		//	return *mPtr;
		//}
	protected:
		Object* mPtr;
		//Vector<Object>* mVec;

	private:
		Object* operator->() const
		{
			return mPtr;
		}

	};


	template<typename Object>
	class Vector
	{
	public:
		explicit  Vector() : theSize{ 0 },
			theCapacity{ SPARE_CAPACITY }
		{
			objects = new Object[theCapacity];
		}

		explicit  Vector(int pInitSize = 0) : theSize{ pInitSize },
			theCapacity{ pInitSize + SPARE_CAPACITY }
		{
			objects = new Object[theCapacity];
		}

		Vector(const Vector& rhs) : theSize{ rhs.theSize },
			theCapacity{ rhs.theCapacity },
			objects{ nullptr }
		{
			objects = new Object[theCapacity];
			for (int k = 0; k < theSize; k++)
			{
				objects[k] = rhs.objects[k];
			}
		}

		Vector(Vector&& rhs) : theSize{ rhs.theSize },
			theCapacity{ rhs.theCapacity },
			objects{ rhs.objects }
		{
			rhs.theSize = 0;
			rhs.theCapacity = 0;
			rhs.objects = nullptr;
		}

		~Vector()
		{
			delete[] objects;
		}

		Vector& operator=(const Vector& rhs)
		{
			Vector copy = rhs;
			std::swap(*this, copy);
			return *this;
		}

		Vector& operator= (Vector&& rhs)
		{
			std::swap(theSize, rhs.theSize);
			std::swap(theCapacity, rhs.theCapacity);
			std::swap(objects, rhs.objects);
			return *this;
		}

		bool  valididnex(const int& index)
		{
			return ((index >= 0) && (index < theSize));
		}

		Object& operator[](int index)
		{
			if (valididnex(index))
				return objects[index];
			else
				throw std::exception("out of range.");
		}

		const Object& operator[](int index) const
		{
			if (valididnex(index))
				return objects[index];
			else
				throw std::exception ("out of range.");
		}

		void resize(const int& pNewSize)
		{
			if (pNewSize > size())
			{
				reserve(pNewSize * 2);
			}
			theSize = pNewSize;
		}


		void reserve(const int& pNewCapacity)
		{
			if (pNewCapacity < size())
				return;

			Object* newArray = new Object[pNewCapacity];
			for (int i = 0; i < size(); i++)
			{
				newArray[i] = std::move(objects[i]);
			}
			theCapacity = pNewCapacity;
			std::swap(objects, newArray);
			delete[] newArray;
		}


		const int size() const
		{
			return theSize;
		}

		const bool empty() const
		{
			return size() == 0;
		}

		void push_back(const Object& pX)
		{
			if (size() == theCapacity)
				reserve(2 * theCapacity + 1);

			objects[theSize++] = pX;
		}

		void pop_back()
		{
			theSize--;
		}

		//修改这一部分
		//typedef Object* VectorIterator;
		//typedef const Object* const_VectorIterator;

		//VectorIterator begin()
		//{
		//	return &objects[0];
		//}

		//const_VectorIterator begin() const
		//{
		//	return &objects[0];
		//}
		//VectorIterator end()
		//{
		//	return &objects[size() - 1 ];
		//}

		//const_VectorIterator end() const
		//{
		//	return &objects[size() - 1];
		//}


		VectorIterator<Object> begin()
		{
			return VectorIterator<Object>(&objects[0]);
		}
		//const_iterator begin() const
		//{
		//	return const_iterator(*this, &objects[0]);
		//}
		VectorIterator<Object> end()
		{
			return VectorIterator<Object>(&objects[size()]);
		}
		//const_iterator end() const
		//{
		//	return const_iterator(*this, &objects[size()]);
		//}

		static const int SPARE_CAPACITY = 16;
	private:
		int theSize;
		int theCapacity;
		Object* objects;
	};


}
