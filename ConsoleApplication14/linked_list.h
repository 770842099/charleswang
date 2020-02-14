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
	void add(int data);
	void addLast(int data);
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
};

//LinkedList::LinkedList() {
//	this->length = 0;
//	this->head = NULL;
//}

//LinkedList::~LinkedList() {
//	//std::cout << "LIST DELETED";
//}
//
//void LinkedList::add(int data) {
//	LinkedListNode* node = new LinkedListNode();
//	node->data = data;
//	node->next = this->head;
//	this->head = node;
//	this->length++;
//}
//
//void LinkedList::print() {
//	LinkedListNode* head = this->head;
//	int i = 1;
//	while (head) {
//		std::cout << i << ": " << head->data << std::endl;
//		head = head->next;
//		i++;
//	}
//}

//int main(int argc, char const *argv[])
//{
//	LinkedList* list = new LinkedList();
//	for (int i = 0; i < 100; ++i)
//	{
//		list->add(rand() % 100);
//	}
//	list->print();
//	std::cout << "List Length: " << list->length << std::endl;
//	delete list;
//	return 0;
//}