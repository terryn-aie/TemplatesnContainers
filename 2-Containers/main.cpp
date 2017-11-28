#include "intvector.h"
#include "test.h"

int main()
{
	intVector nums;

	nums.append(1);
	nums.append(4);
	nums.append(4);
	nums.append(4);
	nums.append(5);

	nums.Erase(3);
	nums.Insert(2, 4);
	int howManyFours = nums.Count(4);
	nums.printVector();
	//
	assertEqual(howManyFours, 3);
	nums.Reserve(50);
	assertEqual((int)nums.getCapacity(), 50);
	nums.Compact();
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
	while (true) {};
	return 0;
}