#pragma once

template<typename T>
class iterator
{
public:
	iterator() = delete;

	iterator(T& container, int initialIndex)
		: owningContainer(&container)
		, currentIndex(initialIndex)
	{

	}

	iterator(const iterator<T>& other)
		: owningContainer(other.owningContainer)
		, currentIndex(other.currentIndex)
	{
	}

	iterator<T>& operator=(const iterator<T>& other)
	{
		owningContainer = other.owningContainer;
		currentIndex = other.currentIndex;
	}
	
	bool operator==(const iterator<T>& other)
	{
		bool isSameContainer = owningContainer == other.owningContainer;
		bool isSameIndex = currentIndex == other.currentIndex;

		return isSameContainer && isSameIndex;
	}

	bool operator!=(const iterator<T>& other)
	{
		bool isSameContainer = owningContainer == other.owningContainer;
		bool isSameIndex = currentIndex == other.currentIndex;

		return !isSameContainer || !isSameIndex;
	}
	//
	auto& operator*()
	{
		return owningContainer->at(currentIndex);
	}
	//
	iterator<T>& operator++()
	{
		++currentIndex;
		return *this;
	}
	iterator<T>& operator++(int previousValue)
	{
		iterator<T> tmp(owningContainer, currentIndex);
		operator++();
		return tmp;
	}

private:
	T* owningContainer;
	int			currentIndex;
};
