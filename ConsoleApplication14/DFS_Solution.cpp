#include "DFS_Solution.h"
#include "LibInclude.h"
void DFS_Solution::test()
{
	//placePlates();
	go2DMaxtirx();
}

void DFS_Solution::placePlates()
{
	//place m to multiple level, the plates on the high level should be bigger than previous one
	stack<int> s;
	int n = 12;
	placePlatesDetails(n, s);
}

void DFS_Solution::placePlatesDetails(int n, stack<int> s)
{
	if (n == 0)
	{
		cout << endl;
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}	
		return;
	}
	int last;
	if (!s.empty())
		last = s.top();
	else
		last = n;
	for (int i = last - 1; i > 0; i--)
	{
		s.push(i);
		n -= i;
		placePlatesDetails(n, s);

		//restore
		s.pop();
		n += i;
	}
}

void DFS_Solution::go2DMaxtirx()
{
	vector<vector<char>> g=
	   {
			{'A', 'B', 'C', 'E'},
			{'S', 'F', 'C', 'S'},
			{'A', 'D', 'E', 'E'}
	};

	bool visited[3][4] = { false };
	
	string word = "ABCCED";
	vector<pair<int, int>> s;
	for (int i = 0; i < g.size(); i++)
	{
		for (int j = 0; j < g[0].size(); j++)
		{
			if (g[i][j] == word[0])
				s.emplace_back(i, j);
		}
	}

	for (pair<int, int> start : s)
	{
		visited[start.first][start.second] = true;
		go2DMaxtirxDetail(word, 1, start.first, start.second, g, visited);
		visited[start.first][start.second] = false;
	}
}

void DFS_Solution::go2DMaxtirxDetail(string s, int index, int x, int y, vector<vector<char>> g, bool visited[3][4])
{
	if (index == s.size())
	{
		cout << true;
		return;
	}
	int pos[4][2] = { {-1,0},{1,0}, {0,1}, {0, -1} };

	for (int i = 0; i < 4; i++)
	{
		int xnew = x + pos[i][0];
		int ynew = y + pos[i][1];
		if (xnew >=0 && xnew < 3 && ynew >= 0 && ynew < 4 && g[xnew][ynew] == s[index])
		{
			visited[xnew][ynew] = true;
			go2DMaxtirxDetail(s, index+1, xnew, ynew, g, visited);
			visited[xnew][ynew] = false;
		}
	}
}



