#include "LinkedList_Solution.h"
void LinkedList_Solution::test()
{
	isPalindrome();
}

void LinkedList_Solution::isPalindrome()
{
	LinkedList s;
	s.addLast(1);
	s.addLast(2);
	s.addLast(2);
	s.addLast(1);

	LinkedList s_reversed;
	
	LinkedListNode* node = s.head;
	while (node != NULL)
	{
		s_reversed.add(node->data);
		node = node->next;
	}

	LinkedListNode* first = s.head;
	LinkedListNode* reversed = s_reversed.head;

	bool matched = true;
	while (first != NULL && reversed != NULL)
	{
		if (first->data != reversed->data)
		{
			matched = false;
			break;
		}
		first = first->next;
		reversed = reversed->next;
	}

	cout << matched && first == NULL && reversed == NULL;




}
