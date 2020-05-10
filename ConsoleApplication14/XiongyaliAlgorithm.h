#pragma once
#include "LibInclude.h"

//匈牙利算法，二分图匹配
class XiongyaliAlgorithm
{
public:
	/**
	 * @param target: the target string
	 * @param words: words array
	 * @return: whether the target can be matched or not
	 */
	vector<int>arr[25];
	bool vis[25];
	int belong[25];
	bool dfs(int now) {
		for (int i = 0; i < arr[now].size(); i++) {
			int v = arr[now][i];
			if (vis[v])continue;
			vis[v] = 1;
			if (belong[v] == -1 || dfs(belong[v])) {
				belong[v] = now;
				return true;
			}
		}
		return false;
	}
	bool matchFunction(string &target, vector<string> &words) {
		// Write your code here
		int len = target.length(), i, j, k, n = words.size();
		for (i = 0; i < len; i++) {
			for (j = 0; j < n; j++) {
				int len2 = words[j].length();
				for (k = 0; k < len2; k++) {
					if (words[j][k] == target[i]) {
						arr[i].push_back(j);
						break;
					}
				}
			}
		}
		bool flag = 1;
		memset(belong, -1, sizeof(belong));
		for (i = 0; i < len; i++) {
			memset(vis, 0, sizeof(vis));
			if (!dfs(i)) {
				return false;
			}
		}
		return true;
	}
};

