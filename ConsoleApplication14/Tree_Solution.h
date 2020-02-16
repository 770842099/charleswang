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
	void test();
	TreeNode* init();
	void midTraverse(TreeNode *root);

	vector<int> NLConstruction();

	void priorMidRecreation();
	TreeNode* priorMidRecreationDetail(string middle, string first, unordered_map<char, int> map);

	void commonAncestor();
	TreeNode* Create(vector<TreeValue> values);
    void commonAncestorDetails(TreeNode* t, vector<int> parents, vector<int>& s1, int v1, vector<int>& s2, int v2);
};