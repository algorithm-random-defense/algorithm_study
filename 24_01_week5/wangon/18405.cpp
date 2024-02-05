#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int> > map(n, vector<int>(n));
	vector<pair<int, int> > virus;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
				virus.push_back(make_pair(map[i][j], i * n + j));
		}
	}
	sort(virus.begin(), virus.end());
	int s, x, y;
	cin >> s >> x >> y;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	while (s--)
	{
		vector<pair<int, int> > tmp;
		for (int v = 0; v < virus.size(); v++)
		{
			int virusNum = virus[v].first;
			int i = virus[v].second / n;
			int j = virus[v].second % n;
			for (int d = 0; d < 4; d++)
			{
				int ni = i + dx[d];
				int nj = j + dy[d];
				if (ni < 0 || ni >= n || nj < 0 || nj >= n)
					continue;
				if (map[ni][nj] != 0)
					continue;
				map[ni][nj] = virusNum;
				tmp.push_back(make_pair(virusNum, ni * n + nj));
			}
		}
		virus = tmp;
	}
	cout << map[x - 1][y - 1];
}
