#pragma once

#include <cassert>
#include <cstring>
#include "iterator.h"
template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

	bool grow(size_t minSize);

public:
	tVector();
	~tVector();

	iterator<tVector<T>> begin()
	{
		return iterator<tVector<T>>(*this, 0);
	}

	iterator<tVector<T>> end()
	{
		return iterator<tVector<T>>(*this, size);
	}

	void clear();
	T& at(size_t idx);
	T& append(T val);
	void pop();
	void insert(size_t idx, T value);

	void erase(size_t idx);
	size_t count(T val) const;

	T* c_ptr() const;
	size_t getCapacity() const;
	size_t getSize() const;
	void reserve(size_t newCapacity);
	void compact();

	bool empty() const;

	T front() const;
	T back() const;

	T& operator[](size_t idx);
	T operator[](size_t idx) const;
};

template<typename T>
tVector<T>::tVector()
{
	capacity = 2;
	data = new T[capacity];
	size = 0;
}

template<typename T>
tVector<T>::~tVector()
{
	delete[] data;
}

template<typename T>
T& tVector<T>::at(size_t idx)
{
	return data[idx];
}


template<typename T>
T& tVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	data[size] = val;
	++size;

	return data[size - 1];
}

template<typename T>
bool tVector<T>::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize)
	{
		capacity *= 2;
	}

	T* newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);

	delete[] data;

	data = newData;
	return true;
}

template<typename T>
T* tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
size_t tVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
size_t tVector<T>::getSize() const
{
	return size;
}

template<typename T>
bool tVector<T>::empty() const
{
	return size > 0;
}

template<typename T>
T tVector<T>::front() const
{
	assert(size > 0);
	return data[0];
}

template<typename T>
T tVector<T>::back() const
{
	assert(size > 0);
	return data[size - 1];
}

template<typename T>
void tVector<T>::pop()
{
	assert(size > 0);
	size -= 1;
}

template<typename T>
T& tVector<T>::operator[](size_t idx)
{
	assert(idx < size);
	return data[idx];
}

template<typename T>
T tVector<T>::operator[](size_t idx) const
{
	assert(idx < size);
	return data[idx];
}

template<typename T>
void tVector<T>::clear()
{
	size = 0;
}

template<typename T>
void tVector<T>::erase(size_t idx)
{
	for (size_t i = idx; i < size; i++)
	{
		T temp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}

	size--;
}

template<typename T>
size_t tVector<T>::count(T val) const
{
	size_t counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == val)
		{
			counter++;
		}
	}
	return counter;
}

template<typename T>
void tVector<T>::insert(size_t idx, T value)
{
	assert(idx >= 0);
	assert(idx <= size);

	append(value);

	for (size_t i = size - 1; i > idx; i--)
	{
		T temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

template<typename T>
void tVector<T>::reserve(size_t newCapacity)
{
	if (newCapacity > capacity)
	{
		T * newData = new T[newCapacity];
		memcpy(newData, data, sizeof(T) * size);

		delete[] data;

		data = newData;
		capacity = newCapacity;
	}
}

template<typename T>
void tVector<T>::compact()
{
	if (capacity > size)
	{
		T * newData = new T[size];
		memcpy(newData, data, sizeof(T) * size);

		delete[] data;

		data = newData;
		capacity = size;
	}
}