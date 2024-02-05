// 계란으로 계란치기
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int ret = 0;
int eggs[9];
int power[9];

void func(int idx)
{
	if (idx > n + 1)
		return;
	for (int i = 1; i <= n; i++)
	{
		if (eggs[idx] <= 0)
			func(idx + 1);
		else if (eggs[i] <= 0 || idx == i)
			continue;
		else
		{
			eggs[idx] -= power[i];
			eggs[i] -= power[idx];
			func(idx + 1);
			eggs[idx] += power[i];
			eggs[i] += power[idx];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (eggs[i] <= 0)
			cnt++;
		ret = max(ret, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> eggs[i] >> power[i];
	func(1);
	cout << ret;
}
