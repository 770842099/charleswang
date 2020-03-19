#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;
class LinkedListNode
{
public:
	LinkedListNode* next;
	int data;
};

class LinkedList
{
public:
	int length;
	LinkedListNode* head;
	LinkedListNode* last;
	LinkedList() {
		this->length = 0;
		this->head = NULL;
		this->last = NULL;
	}
	~LinkedList() {};
	void print() {
		LinkedListNode* head = this->head;
		int i = 1;
		while (head) {
			//std::cout << i << ": " << head->data << std::endl;
			std::cout << head->data << std::endl;
			head = head->next;
			i++;
		}
	}

	void add(int data) {
		LinkedListNode* node = new LinkedListNode();
		node->data = data;
		node->next = this->head;

		this->head = node;
		this->length++;
		if (length == 1)
			last = node;
	}

	void addLast(int data) {
		LinkedListNode* node = new LinkedListNode();
		node->data = data;
		node->next = NULL;
		this->length++;

		if (length == 1)
		{
			last = node;
			head = node;
		}
		else
		{
			this->last->next = node;
			this->last = node;
		}
	}
};
