#include <iostream>

using namespace std;
class ListNode {
public:
	int val;
	int length;
	ListNode *next;
	ListNode* head;
	ListNode* last;
	ListNode() {
		this->length = 0;
		this->head = this;
		this->last = this;
	}
	~ListNode() {};
	void print() {
		ListNode* head = this->head;
		int i = 1;
		while (head) {
			//std::cout << i << ": " << head->data << std::endl;
			std::cout << head->val << std::endl;
			head = head->next;
			i++;
		}
	}

	void add(int data) {
		ListNode* node = new ListNode();
		node->val = data;
		node->next = this->head;

		this->head = node;
		this->length++;
		if (length == 1)
			last = node;
	}

	void addLast(int data) {
		this->length++;

		if (length == 1)
		{
			this->val = data;
		}
		else
		{
			ListNode* node = new ListNode();
			node->val = data;
			node->next = NULL;
			
			
			this->last->next = node;
			this->last = node;
		}
	}

};