#include "Tree_Solution.h"
#include <cstddef>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

TreeNode* Tree_Solution::init()
{
	TreeValue values[] = { {2,1,3},{4,2,6},{6,5,7},{7,NULL,8} };
	int length = sizeof(values) / sizeof(values[0]);
	unordered_set<int> rootvalue;
	for (int i = 0; i < length; i++)
	{
		rootvalue.insert(values[i].node);
	}

	for (int i = 0; i < length; i++)
	{
		rootvalue.erase(values[i].left);
		rootvalue.erase(values[i].right);
	}
	cout << *rootvalue.begin();

	unordered_map<int, pair<int, int>> parentchild;

	//parentchild.find(333) != parentchild.end();

	for (TreeValue value : values)
	{
		parentchild[value.node] = make_pair(value.left, value.right);
	}

	queue<TreeNode*> qnode;
	TreeNode* noderoot = new TreeNode(*rootvalue.begin());
	qnode.push(noderoot);

	while (!qnode.empty())
	{
		TreeNode* nodevalue = qnode.front();
		qnode.pop();
		pair<int, int> children = parentchild[nodevalue->val];
		if (children.first != NULL)
		{
			TreeNode* left = new TreeNode(children.first);
			nodevalue->left = left;
			qnode.push(left);
		}

		if (children.second != NULL)
		{
			TreeNode* right = new TreeNode(children.second);
			nodevalue->right = right;
			qnode.push(right);
		}
	};

	return noderoot;
}

void Tree_Solution::midTraverse(TreeNode *root)
{
	if (root == NULL)
		return;
	midTraverse(root->left);

	cout << root->val << " ";
	midTraverse(root->right);
}


void NLParse(stack<int> states, string& s, int pos, int height, int maxlength, vector<int>& ans)
{
	maxlength = max(maxlength, height);
	if (pos == s.length())
	{
		ans.push_back(maxlength);
		return;
	}

	if (states.empty())
		return;

	int state = states.top();
	if (state == 0 || state == 3)
	{
		states.pop();
		NLParse(states, s, pos, height-1, maxlength, ans);
	}
	else
	{
		if (state == 1)
		{
			//go to left
			int& state = states.top();
			state = 2;
			states.push(s[pos] != 'L');
			NLParse(states, s, pos+1, height+1, maxlength, ans);
			states.pop();

			//go to right
			state = states.top();
			state = 3;
			states.push(s[pos] != 'L');
			NLParse(states, s, pos+1, height+1, maxlength, ans);
			states.pop();
		}
		else
		{
			int& state = states.top();
			state = 3;
			states.push(s[pos] != 'L');
			NLParse(states, s, pos + 1, height+1, maxlength, ans);
			states.pop();

			states.pop();
			NLParse(states, s, pos, height-1, maxlength, ans);
		}
	}

}


vector<int> Tree_Solution::NLConstruction()
{
	//preorder "NNLLL" N no leaf node,  L:leaf node
	//second 0 leaf,  1 not traverse, 2 left traverse, 3 right traverse,

	stack<int> state;
	vector<int> ans;
	string s = "NNLLL";
	state.push(s[0] != 'L');
	NLParse(state, s, 1, 1, 0, ans);

	for (auto&i : ans)
		cout << i << endl;
	return ans;
}



