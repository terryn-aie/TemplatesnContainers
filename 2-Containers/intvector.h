#pragma once

// intvector.h

class intVector
{
	int * data;			// ptr to your dynamically allocated array
	size_t capacity;	// total capacity
	size_t size;		// total number of elements stored

public:
	intVector();
	~intVector();

	int& at(size_t idx);

	int& append(int val);

	int* c_ptr() const;
	
	size_t getCapacity() const;
	size_t getSize() const;

	bool empty() const;

	int front() const;
	int back() const;

private:
	bool grow(size_t minSize);
};