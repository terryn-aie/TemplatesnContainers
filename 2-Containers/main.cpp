#include "test.h"

#include "intvector.h"
#include "tvector.h"
#include "intlinkedlist.h"
#include "algorithms.h"
#include <vector>
#include <list>
#include <numeric>


int main()
{
	

	int totalTest = std::accumulate(nums.begin(), nums.end(), 0);


	auto iter = nums.begin();
	++iter;
	++iter;
	int value = *iter;
	*iter = 10;

	tVector<int> nums;
	nums.append(1);
	nums.append(3);
	nums.append(5);
	nums.append(7);
	nums.append(9);

	auto begin = nums.begin();
	auto end = nums.end();

	int total = addRange(begin, end);


	int arrayOfNums[] = { 1, 3, 5, 7, 9 };
	int total2 = addRange<int*, int>(arrayOfNums, arrayOfNums + 5);

	/*
	std::vector<int> exampleNums = { 1, 3, 5, 7, 9 };
	auto blah = addRangeFinished<std::vector<int>::iterator, int>(
		exampleNums.begin(),
		exampleNums.end()
		);

	std::list<int> exampleNumsInList = { 1, 3, 5, 7, 9 };
	auto blah2 = addRangeComplex(exampleNumsInList.begin(), exampleNumsInList.end());
	*/

	int a = 3;
	/*
	int arrayOfNums[] = { 1, 3, 5, 7, 9 };
	auto blah3 = addRangeComplex(arrayOfNums, arrayOfNums + 5);

	int nums[] = { 1, 3, 5, 7, 9 };
	int* start = nums;
	int* end = start + 5;
	
	int total = addRange(start, end);

	/*auto a = add(5, 3.4f);
	auto b = add(3.4f, 5);

	intLinkedList list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.insert(3,4);

	//assert(list.Count(1) == 3);


	/*intLinkedList list2 = list1;

	intLinkedList list3;
	list3 = list1;*/


	/*
	std::vector<int> linkedList = { 1, 2, 3, 4 };

	auto loc = std::find(linkedList.begin(), linkedList.end(), 3);
	

	intLinkedList nums;
	nums.append(1);
	nums.append(2);
	nums.append(3);
	nums.append(4);

	assertEqual(nums.at(2), 3);
	assertEqual(nums.at(7), 0);

	/*
	tVector<int> nums;
	int bytes = sizeof(unsigned);
	nums.append(1);
	nums.append(4);
	nums.append(4);
	nums.append(4);
	nums.append(5);

	nums.erase(3);
	nums.insert(2, 4);
	int howManyFours = nums.count(4);
	//nums.printVector();
	//
	assertEqual(howManyFours, 3);
	nums.reserve(50);
	assertEqual((int)nums.getCapacity(), 50);
	nums.compact();
	assertEqual((int)nums.getCapacity(), (int)nums.getSize());
	/*assertEqual<size_t>(nums.getCapacity(), 2);





	nums.append(1);
	nums.append(5);

	assertEqual(nums.at(0), 1);
	assertEqual(nums.at(1), 5);

	nums.append(33);

	assertEqual(nums.at(0), 1);
	assertEqual(nums.at(1), 5);
	assertEqual(nums.at(2), 33);
	assertEqual<size_t>(nums.getCapacity(), 4);
	assertEqual<size_t>(nums.getSize(), 3);
	assert<false>(nums.empty());
	assertEqual(nums.front(), 1);
	assertEqual(nums.back(), 33);
	assertEqual(nums.c_ptr(), &nums.at(0));*/

	//nums[1] // 5

	//intVector a;
	//intVector b(a);
	//intVector c;
	//c = a;

	//while (true) {};
	return 0;
}