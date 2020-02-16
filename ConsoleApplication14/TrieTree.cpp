#include "TrieTree.h"
#include "LibInclude.h"
TrieTree::TrieTree()
{
	root = new TrieTreeNode();
}

void TrieTree::test()
{
	add("abcd");
	cout << exist("abcd") << endl;
	cout << completedExist("abc")<<endl;
}

bool TrieTree::exist(string word)
{
	int size = (int)word.length();
	bool match = true;
	TrieTreeNode * cur = this->root;
	for (int i=0;i<size;i++)
	{
		cur = cur->node[word[i] - 'a'];
		if (cur == NULL)
		{
			match = false;
			break;
		}
	}
	return match;
}

bool TrieTree::completedExist(string word)
{
	int size = (int)word.length();
	bool match = true;
	TrieTreeNode * cur = this->root;
	for (int i = 0; i < size; i++)
	{
		cur = cur->node[word[i] - 'a'];
		if (cur == NULL)
		{
			match = false;
			break;
		}
	}
	return match && (cur->isLeaf);
}

void TrieTree::add(string word)
{
	int size = (int)word.length();
	bool match = true;
	TrieTreeNode * cur = this->root;
	int i=0;
	for (;i < size; i++)
	{
		if (cur->node[word[i] - 'a'] == NULL)
		{
			match = false;
			break;
		}
		else
		{
			cur = cur->node[word[i]-'a'];
		}
	}

	for (; i < size; i++)
	{
		cur->node[word[i]-'a'] = new TrieTreeNode();
		cur = cur->node[word[i] - 'a'];
	}
	cur->isLeaf = true;
}
