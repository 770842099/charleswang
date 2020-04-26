#pragma once
#include <string>
using namespace std;
struct TrieTreeNode
{
	TrieTreeNode* node[26];
	bool isLeaf = false;
};

class TrieTree
{
public:
	TrieTree();
	bool exist(string word);
	void add(string word);
	bool completedExist(string word);
	void test();
	TrieTreeNode *root;

	string getPrefix(string str);
};



