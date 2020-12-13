#include "LinkedList_Solution.h"
#include "LibInclude.h"
void LinkedList_Solution::test()
{
	//isPalindrome();
	mergeTwoLists();
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

ListNode* LinkedList_Solution::mergeTwoLists()
{
	ListNode* l1=new ListNode();
	ListNode* l2=new ListNode();
	l1->addLast(1);
	l1->addLast(3);
	l1->addLast(8);
	l1->addLast(11);
	l1->addLast(15);

	l2->addLast(2);

	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode* ans=new ListNode();
	ListNode* temp = ans;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val > l2->val)
		{
			temp->next = l2;
			l2 = l2->next;			
		}
		else
		{
			temp->next = l1;
			l1 = l1->next;
		}
		temp = temp->next;

		if (l1 == NULL)
			temp->next = l2;
		else if (l2 == NULL)
			temp->next = l1;
	}

	ans = ans->next;

	ans->print();

	return ans;
}

int LinkedList_Solution::getWinner(vector<int>& arr, int k) {
	list<int> s;
	if (k > arr.size() - 1)
		k = arr.size() - 1;

	for (int&i : arr) {
		s.push_back(i);
	}

	int round = -1;
	int big = -99999999;
	int curBigNum;
	int curSmallNum;
	while (round < k)
	{
		list<int>::iterator seconde_iterator;
		seconde_iterator = ++s.begin();

		int aa = *s.begin();
		int bb = *seconde_iterator;

		if (*seconde_iterator > *s.begin()) {
			curBigNum = *seconde_iterator;
			curSmallNum = *s.begin();
		}
		else {
			curBigNum = *s.begin();
			curSmallNum = *seconde_iterator;
		}
		if (curBigNum == big)
		{
			round++;
		}
		else
		{
			round = 1;
		}
		big = curBigNum;

		if (*seconde_iterator > *s.begin()) {
			s.erase(s.begin());
			s.push_back(curSmallNum);
		}
		else
		{
			s.erase(seconde_iterator);
			s.push_back(curSmallNum);
		}
	}

	return curBigNum;

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//class Solution {
//public:
//	ListNode* plusOne(ListNode* head) {
//		if (head == NULL)
//			return NULL;
//		ListNode* curHead = reversed(head);
//		ListNode* temp = curHead;
//		ListNode* pre = temp;
//		while (temp != NULL) {
//			if (temp->val == 9) {
//				temp->val = 0;
//				pre = temp;
//				temp = temp->next;
//			}
//			else {
//				temp->val++;
//				break;
//			}
//		}
//		if (temp == NULL && pre->val == 0) {
//			pre->next = new ListNode(1);
//		}
//		return reversed(curHead);
//	}
//
//	ListNode* reversed(ListNode* head) {
//		ListNode* curHead = head;
//		ListNode* next = head->next;
//		curHead->next = NULL;
//		while (next != NULL) {
//			ListNode* nextTemp = next->next;
//			next->next = curHead;
//			curHead = next;
//			next = nextTemp;
//		}
//		return curHead;
//	}
//};

//ListNode* reversed = new ListNode(1);
//ListNode* cur = reversed;
//for (int i = 2; i <= 10; i++) {
//	ListNode* node = new ListNode(9);
//	cur->next = node;
//	cur = cur->next;
//}
//
//Solution s;
//ListNode* temp = s.plusOne(reversed);
//while (temp != NULL) {
//	cout << temp->val << endl;
//	temp = temp->next;
//}