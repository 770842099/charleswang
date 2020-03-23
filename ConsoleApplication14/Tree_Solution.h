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

	void NLConstruction2();

	void NLParse(stack<int> states, string& s, int pos, int height, int maxlength, vector<int>& ans);
	int NLParse2(string s, int start, int end);

	void priorMidRecreation();
	TreeNode* priorMidRecreationDetail(string middle, string first, unordered_map<char, int> map);

	void commonAncestor();
	TreeNode* Create(vector<TreeValue> values);
    void commonAncestorDetails(TreeNode* t, vector<int> parents, vector<int>& s1, int v1, vector<int>& s2, int v2);

	TreeNode* createTree(vector<int> v);
	
	TreeNode* createTreeWithNum(int start, int end);

	void print2DUtil(TreeNode*root, int space);

	//leetcode 549
	void binaryTreeOrder();
	int* binaryTreeOrderDetails(TreeNode* node, int& result);



};