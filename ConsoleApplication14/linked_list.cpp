#include "linked_list.h"

void LinkedList::add(int data) {
	LinkedListNode* node = new LinkedListNode();
	node->data = data;
	node->next = this->head;

	this->head = node;
	this->length++;
	if (length==1)
		last = node;
}

void LinkedList::addLast(int data) {
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