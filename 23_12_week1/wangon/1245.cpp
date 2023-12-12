#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dirx[8] = {-1, -1 ,-1, 0, 0, 1, 1, 1};
int diry[8] = {1, 0, -1, 1, -1, 1, 0, -1};

bool peak;
int cnt = 0;
int n, m;
int mountain[101][71];
int checker[101][71];

void func(int x, int y)
{
	for (int dfs = 0; dfs < 8; dfs++)
	{
		int dx = x + dirx[dfs];
		int dy = y + diry[dfs];

		if (dx < 0 || dy < 0 || dx >= n || dy >= m)
			continue ;
		if (mountain[x][y] < mountain[dx][dy])
			peak = false;
		if (checker[dx][dy] == 1)
			continue ;
		if (mountain[x][y] == mountain[dx][dy])
		{
			checker[dx][dy] = true;
			func(dx, dy);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mountain[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			checker[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (checker[i][j])
				continue ;
			peak = true;
			checker[i][j] = 1;
			func(i, j);
			if (peak)
				cnt++;
		}
	}
	cout << cnt << endl;
}
