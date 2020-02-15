#pragma once
#include <cstddef>
#include <vector>
#include "LibInclude.h"
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeValue {
	int node;
	int left;
	int right;

	TreeValue(int _node, int _left, int _right)
	{
		node = _node;
		left = _left;
		right = _right;
	}
};



class Tree_Solution
{
public:
	TreeNode* init();
	void midTraverse(TreeNode *root);

	vector<int> NLConstruction();

	void priorMidRecreation();
	TreeNode* priorMidRecreationDetail(string middle, string first, unordered_map<char, int> map);
};