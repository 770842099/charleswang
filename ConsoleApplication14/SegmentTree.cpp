#include "SegmentTree.h"
#include "LibInclude.h"
void SegmentTree::test()
{
	vector<vector<int>> positions = { {1,2},{2,3},{6,1} };
	SegmentTree_Node* root = new SegmentTree_Node(0, 1e9);
	vector<int> ret;
	for (auto pos : positions) {
		int maxHeight = root->query(pos[0], pos[0] + pos[1] - 1);
		int newHeight = maxHeight + pos[1];
		root->update(pos[0], pos[0] + pos[1] - 1, newHeight);
		ret.push_back(root->query(0, 1e9));
	}
	for (int i : ret)
		cout << i << " ";
}