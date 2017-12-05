#pragma once

class intLinkedList
{
public:
	struct intLinkedListNode
	{
		int value;
		intLinkedListNode* next;
		intLinkedListNode* prev;
	};

	intLinkedList();
	intLinkedList(const intLinkedList& other);

	~intLinkedList();

	void append(int value);

	int at(int index);

	size_t size() const;

	bool empty() const;

	int front() const;
	int back() const;
	void clear();
	void erase(size_t idx);
	int Count(int value);
	void insert(size_t idx, int value);
private:
	intLinkedListNode* head;


};