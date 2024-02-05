#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int n, m;
vector<int> ladder(101, 0);
int Visit[101];

void func()
{
	queue<int> q;
	q.push(1);
	memset(Visit, 0, sizeof(Visit));
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int nx = ladder[x + i];
			if (nx > 100)
				continue;
			if (Visit[nx] <= Visit[x] + 1 && Visit[nx])
				continue;
			q.push(nx);
			Visit[nx] = Visit[x] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= 100; i++)
		ladder[i] = i;
	for (int i = 0; i < n + m; i++)
	{
		int start, dest;
		cin >> start >> dest;
		ladder[start] = dest;
	}
	func();
	cout << Visit[100];
}
