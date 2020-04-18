#include "Map_Solution.h"
#include "UnionSetUtil.h"

void Map_Solution::test()
{
	//numberOfIslands();
	//puzzle();

	maxSquare();
}

int Map_Solution::numberOfIslands()
{
	int s[8][8] = {
		{0,1,1,1,0,0,0,0},
		{0,1,1,1,0,0,0,0},
		{0,1,1,1,0,0,1,1},
		{0,1,1,1,0,1,1,0},
		{0,0,0,0,0,0,1,1},
		{0,1,1,1,0,0,0,0},
		{0,1,1,1,0,0,1,1},
		{0,1,1,1,0,1,1,0}
	};

	int d[4][2] =
	{
		{0,-1},{0,1},{-1,0},{1,0}
	};
	int count = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (s[i][j] != 0)
			{
				s[i][j] = 0;
				count++;

				queue<pair<int, int>> q;
				q.emplace(i, j);
				while (!q.empty())
				{
					queue<pair<int, int>>qtemp;
					while (!q.empty())
					{
						pair<int, int> index = q.front();
						q.pop();
						for (int k = 0; k < 4; k++)
						{
							int x = index.first + d[k][0];
							int y = index.second + d[k][1];
							if (x >= 0 && x < 8 && y >= 0 && y < 8 && s[x][y] == 1)
							{
								s[x][y] = 0;
								qtemp.emplace(x, y);
							}
						}
					}
					q = qtemp;
				}
			}
		}
	cout << count;
	return count;
}

int Map_Solution::puzzle()
{
	vector<vector<int>> s = {
		{0,0,1,0,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{1,1,0,1,1},
		{0,0,0,0,0}
	};

	vector<vector<int>> distance = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};

	int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

	pair<int, int> start{ 0,4 };
	pair<int, int> end{ 4,4 };
	queue<vector<int>> q;
	q.push(vector<int>{0, 4, 0});

	while (!q.empty())
	{
		queue<vector<int>> qtemp;

		while (!q.empty())
		{
			vector<int> t = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int x = t[0]; 
				int y = t[1];
				int path = 0;
				int last_x = x;
				int last_y = y;
				do
				{
					last_x = x;
					last_y = y;
					x += direction[i][0];
					y += direction[i][1];
					if (x >= 0 && x <= 4 && y >= 0 && y <= 4 && s[x][y]==0)
					{
						path++;
					}
					else
						break;
				} while (true);
				if (path > 0)
				{
					if (distance[last_x][last_y] == 0)
					{
						distance[last_x][last_y] = t[2] + path;
						qtemp.push(vector<int>{last_x, last_y, t[2] + path });
					}
				}
			}
		}
		q = qtemp;
	}
	cout << distance[4][4] << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << distance[i][j] << " ";
		cout << endl;
	}

	return distance[4][4];
}

int Map_Solution::maxSquare()
{
	vector<vector<int>> matrix = {
		{ 1, 1, 0},
		{1, 1, 0}};

	int row = matrix.size();
	int column = matrix[0].size();
	int mini = min(row, column);


	int maxLenght = 0;
	vector<vector<vector<bool>>> dp(row, vector<vector<bool>>(column, vector<bool>(mini + 1, false)));


	for (int length = 1; length <= mini; length++)
	{
		bool Existed = false;
		for (int i = 0; i < row-(length -1); i++)
		{
			for (int j = 0; j < column-(length -1); j++)
			{
				if (length == 1)
					dp[i][j][length] = matrix[i][j] == 1;
				else
				{
					dp[i][j][length] = dp[i][j][length-1] && dp[i+1][j][length-1] && dp[i][j+1][length-1] && dp[i+1][j+1][length-1];
				}
				if (dp[i][j][length] && length > maxLenght)
				{
					maxLenght = length;
					Existed = true;
				}
			}
		}
		if (!Existed)
			break;
	}

	cout << maxLenght * maxLenght;
	return maxLenght* maxLenght;
}