// 근손실
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k, cnt = 0;
vector<int> day(8);
vector<int> Visit(8, 0);

void func(int idx, int nLimit)
{
	if (nLimit < 500)
		return;
	if (idx == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!Visit[i])
		{
			nLimit += (day[i] - k);
			Visit[i] = 1;
			func(idx + 1, nLimit);
			Visit[i] = 0;
			nLimit -= (day[i] - k);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> day[i];
	func(0, 500);
	cout << cnt;
}
