#include "DFS_Solution.h"
#include "LibInclude.h"
void DFS_Solution::test()
{
	//placePlates();
	//go2DMaxtirx();
	//mergeStones();

	smallestSufficientTeam();
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

void DFS_Solution::mergeStones()
{
	vector<int> input{ 3,5,1,2,6 };
	int k = 3;
	vector<vector<int>> dp(input.size(), vector<int>(input.size(), 0));
	vector<int> sum(input.size()+1);
	sum[0] = 0;
	for (int i = 1; i <= input.size(); i++)
	{
		sum[i] = sum[i - 1] + input[i - 1];
	}
	cout<<mergeStonesDetails(input, 0, input.size() - 1, k, dp, sum);
	//cout << mergeStonesDetails(input, 1, 3, k, dp, sum);
}

int DFS_Solution::mergeStonesDetails(vector<int> input, int start, int end, int k, vector<vector<int>> &dp, vector<int>& sum)
{
	vector<vector<int>> splits;
	vector<int> split;
	mergeStonesSplits(start, end, k, 1, split, splits);
	int result = 999999;
	for (int i = 0; i < splits.size(); i++)
	{
		int total = 0;
		for (int j = 0; j < 2 * k; j=j + 2)
		{
			if (splits[i][j] == splits[i][j + 1])
				total += input[splits[i][j]];
			else
			{
				total += mergeStonesDetails(input, splits[i][j], splits[i][j + 1], k, dp, sum);
				total += sum[splits[i][j + 1]+1] - sum[splits[i][j]];
			}
		}
		result = min(result, total);
	}
	dp[start][end] = result;
	return result;
}

void DFS_Solution::mergeStonesSplits(int start, int end, int k, int index, vector<int> split, vector<vector<int>>& splits)
{
	if (index == k + 1)
	{
		if (start == end + 1)
		{
			splits.push_back(split);
		}
		return;
	}


	for (int i = 1; start+i-1 <= end-(k-index); i += k - 1)
	{
		split.push_back(start);
		split.push_back(start+i-1);
		mergeStonesSplits(start + i, end, k, index + 1, split, splits);
		split.pop_back();
		split.pop_back();
	}
}

void DFS_Solution::smallestSufficientTeam()
{
	vector<string> req_skills{ "algorithms", "math", "java", "reactjs", "csharp", "aws" };
	vector<vector<string>> people{ {"algorithms", "math", "java"},
		{"algorithms", "math", "reactjs"},
		{"java", "csharp", "aws"},
		{"reactjs", "csharp"},
		{"csharp", "math"},
		{"aws", "java"} };

	unordered_map<string, int> strMap;
	int count = 0;
	for (string& str : req_skills)
		if (!strMap.count(str))
			strMap[str] = count++;

	vector<pair<int, int>> people2;
	for (int i = 0; i < people.size(); i++)
	{
		pair<int, int> p = { i,0 };
		for (int j = 0; j < people[i].size(); j++)
		{
			if (strMap.count(people[i][j]))
				p.second = p.second | (1 << strMap[people[i][j]]);
		}
		if (p.second)
			people2.push_back(p);
	}

	vector<pair<int, int>> people3;
	for (int i = 0; i < people2.size(); i++)
	{
		bool flag = true;
		for (int j = i + 1; j < people.size(); j++)
		{
			flag = (people2[i].second& people2[j].second) != people2[i].second;
		}
		if (flag)
			people3.push_back(people2[i]);
	}
	people2 = move(people3);

	int req_flags = 0;
	for (string &str : req_skills)
	{
		req_flags |= 1<<strMap[str];
	}

	vector<int> minVal(1 << req_skills.size(), 9999999);
	vector<vector<int>> minNums(1 << req_skills.size(), vector<int>());

	vector<DFS_Solution_smallestSufficientTeam> skillsSet;
	skillsSet.emplace_back(0, 0, vector<int>());

	for (int i = 0; i < people2.size(); i++)
	{
		int l = skillsSet.size();
		for (int j = 0; j < l; j++)
		{
			int skills = skillsSet[j].skills | people2[i].second;
			if (minVal[skills] > skillsSet[j].peoples + 1)
			{
				minVal[skills] = skillsSet[j].peoples + 1;
				vector<int> nums = skillsSet[j].peopleNum;
				nums.push_back(j);
				minNums[skills] = nums;
				skillsSet.emplace_back(skills, minVal[skills], nums);
			}
		}
	}

	for (int &i : minNums[req_flags])
		cout << i << " ";
}