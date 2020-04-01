#include "Tree_Solution.h"
#include "LibInclude.h"
using namespace std;

void Tree_Solution::test()
{
	//commonAncestor();
	//NLConstruction2();

	//print2DUtil(createTreeWithNum(1, 14),0);

	//print2DUtil(createTree(vector<int>{10, 7, 13, 4, 8, 11, 15, 2, 5, NULL,9}),0);

	//binaryTreeOrder();
	//splitBST();

	//constructFromPrePost();
	//allPossibleFBT();

	distributeCoins();
}

TreeNode* Tree_Solution::Create(vector<TreeValue> values)
{
	int length = (int)values.size();
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
	//cout << *rootvalue.begin();

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


TreeNode* Tree_Solution::init()
{
	vector<TreeValue> values = { {2,1,3},{4,2,6},{6,5,7},{7,NULL,8} };
	return Create(values);
}

void Tree_Solution::midTraverse(TreeNode *root)
{
	if (root == NULL)
		return;
	midTraverse(root->left);
	cout << root->val << " ";
	midTraverse(root->right);
}


void Tree_Solution::NLParse(stack<int> states, string& s, int pos, int height, int maxlength, vector<int>& ans)
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

void Tree_Solution::NLConstruction2()
{
	string s = "NNLLL";
	int maxLength = 0;
	cout<<NLParse2(s, 0, s.length()-1);
	
}

int Tree_Solution::NLParse2(string s, int start, int end)
{
	if (start > end)
		return -1;
	else if (start == end)
		if (s[start] == 'N')
			return -1;
		else
			return 1;
	else if (s[start] == 'L')
		return -1;

	int height = -1;
	for (int i = start+1; i <= end; i++)
	{
		int height_left = NLParse2(s, start + 1, i);

		if (height_left != -1)
		{
			int height_right = NLParse2(s, i + 1, end);
			if (height_right != -1)
			{
				height = max(max(height_left, height_right), height);
			}
		}
	}
	return height+1;
}


void Tree_Solution::priorMidRecreation()
{
	string middle = "12345678";
	string first = "42136578";
	unordered_map<char, int> map;
	for (int i = 0; i < middle.size(); i++)
	{
		map.insert(make_pair(middle[i], i));
	}
	TreeNode *root = priorMidRecreationDetail(middle, first, map);
	midTraverse(root);
}

TreeNode* Tree_Solution::priorMidRecreationDetail(string middle, string first, unordered_map<char, int> map)
{
	if (middle.length() == 0)
		return NULL;
	if (middle.length() == 1)
		return new TreeNode(first[0]-'0');

	TreeNode* root = new TreeNode(first[0]-'0');
	string middle_left;
	string middle_right;
	string first_left;
	string first_right;

		int index = (int)middle.find(first[0]);
		middle_left = middle.substr(0, index);
		middle_right = middle.substr(index + 1, middle.size()-1);

		first_left = first.substr(1, index);
		first_right = first.substr(index + 1, first.size() - 1);

		root->left = priorMidRecreationDetail(middle_left, first_left, map);
		root->right = priorMidRecreationDetail(middle_right, middle_right, map);
	return root;
}

void Tree_Solution::commonAncestor()
{
	vector<TreeValue> para1 = { {3,5,1}, {5,6,2},{2,7,4},{1,0,8} };
	TreeNode* tree1 = Create(para1);
	vector<int> parents, s1, s2;
	commonAncestorDetails(tree1, parents, s1, 5, s2, 8);
	unordered_set<int> s;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		s.insert(s1[i]);
	}

	for (int i = s2.size() - 1; i >= 0; i--)
	{
		if (s.count(s2[i]) > 0)
		{
			cout << s2[i] << endl;
			return;
		}
	}
}

void Tree_Solution::commonAncestorDetails(TreeNode* t,vector<int> parents, vector<int>& s1, int v1, vector<int>& s2, int v2)
{
	if (t == NULL)
		return;
	
	if (t->val == v1)
		s1 = parents;
	if (t->val == v2)
		s2 = parents;
	parents.push_back(t->val);
	commonAncestorDetails(t->left, parents, s1, v1, s2, v2);
	commonAncestorDetails(t->right, parents, s1, v1, s2, v2);
}

TreeNode* Tree_Solution::createTree(vector<int> v)
{
	TreeNode * root = new TreeNode(v[0]);
	queue<TreeNode*> q;
	q.push(root);
	for (int i = 1; i < v.size(); i=i+2)
	{
		TreeNode* n = q.front();
		q.pop();
		if (v[i]!= INT_MAX)
			n->left = new TreeNode(v[i]);
		if (v[i+1] != INT_MAX)
			n->right = new TreeNode(v[i + 1]);
		if (n->left != NULL)
			q.push(n->left);
		if (n->right != NULL)
			q.push(n->right);
	}
	return root;
}

TreeNode* Tree_Solution::createTreeWithNum(int start, int end)
{
	int value = (start + end) / 2;
	TreeNode* root = new TreeNode(value);
	if (start < value)
		root->left = createTreeWithNum(start, value - 1);
	if (value < end)
		root->right = createTreeWithNum(value + 1, end);
	return root;
}

void Tree_Solution::print2DUtil(TreeNode*root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += 6;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = 6; i < space; i++)
		cout << " ";
	cout << root->val << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}

void Tree_Solution::binaryTreeOrder()
{
	vector<TreeValue> values = { {2,1,3},{3,4,8},{4,5,6} };
	TreeNode* n= Create(values);
	int result=0;
	binaryTreeOrderDetails(n, result);
	cout << result;
}

//int[0] uptimes, int[1] up number, int[2] downtimes, int[3] down number
int* Tree_Solution::binaryTreeOrderDetails(TreeNode* node, int& result)
{
	if (node == NULL)
	{
		int a[4] = { -110,-100,-110,-110 };
		return a;
	}

	int* left = binaryTreeOrderDetails(node->left, result);
	int* right = binaryTreeOrderDetails(node->right, result);

	//first check up
	int* returnResult = new int[4]{ 1,1,1,1 };
	returnResult[1] = node->val;
	returnResult[3] = node->val;

	if (left[1] + 1 == node->val)
	{
		returnResult[1] = node->val;
		returnResult[0] = left[0] + 1;
	}

	if (right[1] + 1 == node->val)
	{
		returnResult[1] = node->val;
		returnResult[0] = max(right[0]+1, returnResult[0]);
	}

	if (left[3] - 1 == node->val)
	{
		returnResult[3] = node->val;
		returnResult[2] = left[2] + 1;
	}
	cout << "right:"<<right[3] << endl;
	cout << "node->val:" << node->val << endl << endl;
	if (right[3] -1 == node->val)
	{
		returnResult[3] = node->val;
		returnResult[2] = max(right[2] + 1, returnResult[2]);
	}
	
	result = max(returnResult[0] + returnResult[2] - 1, result);
	return returnResult;
}

void  Tree_Solution::splitBST()
{
	vector<TreeValue> values = { {4,2,6},{2,1,3},{6,5,7} };
	TreeNode* n = Create(values);
	vector<TreeNode*> result = splitBSTDetails(n, 2);
	print2DUtil(result[0],4);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	print2DUtil(result[1], 4);

}

vector<TreeNode*> Tree_Solution::splitBSTDetails(TreeNode* root, int n)
{
	if (root == NULL)
		return vector<TreeNode*>{NULL, NULL};

	if (root->val <= n)
	{
		vector<TreeNode*> children = splitBSTDetails(root->right, n);
	
		vector<TreeNode*> result;
		root->right = children[0];
		result.push_back(root);
		result.push_back(children[1]);
		return result;
	}
	else
	{
		vector<TreeNode*> children = splitBSTDetails(root->left, n);

		vector<TreeNode*> result;
		root->left = children[1];
		result.push_back(children[0]);
		result.push_back(root);
		return result;
	}
}


void Tree_Solution::constructFromPrePost()
{
	vector<int> pre{ 1,2,4,5,3,6,7 };
	vector<int> post{ 4, 5, 2, 6, 7, 3, 1 };
	TreeNode *treenode=constructFromPrePostDetails(pre, post);
	print2DUtil(treenode, 4);
}

TreeNode* Tree_Solution::constructFromPrePostDetails(vector<int> pre, vector<int> post)
{
	int N = pre.size();
	if (N == 0) return NULL;

	TreeNode* root = new TreeNode(pre[0]);
	if (N == 1) return root;


	int L = 0;
	for (int i = 0; i < N; ++i)
		if (post[i] == pre[1])
			L = i + 1;

	vector<int> left1(pre.begin()+1, pre.begin()+L+1);
	vector<int> left2(post.begin(), post.begin()+L);
	root->left = constructFromPrePostDetails(left1, left2);


	vector<int> right1(pre.begin()+L+1, pre.begin()+N);
	vector<int> right2(post.begin()+L, post.begin()+N-1);
	root->right = constructFromPrePostDetails(right1, right2);

	return root;
}

void Tree_Solution::allPossibleFBT()
{
	int n = 7;
	unordered_map<int, int> cached;
	cached[1]=1;
	cout << allPossibleFBTDetails(n, cached);
}

int Tree_Solution::allPossibleFBTDetails(int n,  unordered_map<int,int>& cached)
{
	if (cached.count(n) > 0)
		return cached[n];

	int total = 0;
	for (int i = 1; i < n - 1; i+= 2)
		total += allPossibleFBTDetails(i, cached)*allPossibleFBTDetails(n - 1 - i, cached);

	cached[n] = total;
	return total;
}

void Tree_Solution::distributeCoins()
{
	vector<int> input{ 1, 0, 0, INT_MAX, 3 };
	TreeNode* root = createTree(input);
	int times = 0;
	int result=distributeCoinsDetails(root, times);
	cout << times + result;
}

int Tree_Solution::distributeCoinsDetails(TreeNode* node, int& times)
{
	if (node == NULL)
		return 0;
	int leftTimes = distributeCoinsDetails(node->left, times);
	int rightTimes= distributeCoinsDetails(node->right, times);
	times += abs(leftTimes) + abs(rightTimes);

	return leftTimes + rightTimes + node->val- 1;
}










