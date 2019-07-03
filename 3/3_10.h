#pragma once

#include <algorithm>

namespace allen
{
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

		Object& operator[](int index)
		{
			return objects[index];
		}

		const Object& operator[](int index) const
		{
			return objects[index];
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

		}

		//修改这一部分
		typedef Object* iterator;
		typedef const Object* const_iterator;

		iterator begin()
		{
			return &objects[0];
		}

		const_iterator begin() const 
		{
			return &objects[0];
		}
		iterator end()
		{
			return &objects[size()];
		}

		const_iterator end() const
		{
			return &objects[size()];
		}

		static const int SPARE_CAPACITY = 16;
	private:
		int theSize;
		int theCapacity;
		Object* objects;
	};

	
	template<typename Object>
	class Iterator
	{
		explicit Iterator() :mPtr{nullptr}
		{
		}
		explicit Iterator(const Object& pObeject) :mPtr{ &pObeject }
		{ 
		}
		/*
		_Vector_iterator() { // construct with null vector pointer
		}
	
		_Vector_iterator(pointer _Parg, const _Container_base* _Pvector)
			: _Mybase(_Parg, _Pvector) { // construct with pointer _Parg
		}
		_NODISCARD reference operator*() const { // return designated object
			return const_cast<reference>(_Mybase::operator*());
		}
	
		_NODISCARD pointer operator->() const { // return pointer to class object
			return _Const_cast(_Mybase::operator->());
		}
	
		_Vector_iterator& operator++() { // preincrement
			++* (_Mybase*)this;
			return *this;
		}
	
		_Vector_iterator operator++(int) { // postincrement
			_Vector_iterator _Tmp = *this;
			++* this;
			return _Tmp;
		}
	
		_Vector_iterator& operator--() { // predecrement
			--* (_Mybase*)this;
			return *this;
		}
	
		_Vector_iterator operator--(int) { // postdecrement
			_Vector_iterator _Tmp = *this;
			--* this;
			return _Tmp;
		}
	
		_Vector_iterator& operator+=(const difference_type _Off) { // increment by integer
			*(_Mybase*)this += _Off;
			return *this;
		}
	
		_NODISCARD _Vector_iterator operator+(const difference_type _Off) const { // return this + integer
			_Vector_iterator _Tmp = *this;
			return _Tmp += _Off;
		}
	
		_Vector_iterator& operator-=(const difference_type _Off) { // decrement by integer
			return *this += -_Off;
		}
	
		_NODISCARD _Vector_iterator operator-(const difference_type _Off) const { // return this - integer
			_Vector_iterator _Tmp = *this;
			return _Tmp -= _Off;
		}
	
		_NODISCARD difference_type operator-(const _Mybase& _Right) const { // return difference of iterators
			return *(_Mybase*)this - _Right;
		}
	
		_NODISCARD reference operator[](const difference_type _Off) const { // subscript
			return *(*this + _Off);
		}
	
		using _Prevent_inheriting_unwrap = _Vector_iterator;
	
		_NODISCARD pointer _Unwrapped() const {
			return this->_Ptr;
		}*/
	
	private:
		Object* mPtr;
	};



}
