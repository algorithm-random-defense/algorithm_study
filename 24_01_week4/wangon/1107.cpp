#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m, broken, ret;
int button[10];

int pressNum(int target)
{
	// 0번으로 이동할때는 0번이 고장났을때 / 아닐때로 구분
	if (target == 0)
	{
		if (button[0])
			return 1;
		else
			return 0;
	}
	int cnt = 0;
	// 이동할 수 있는 번호까지 하나씩 검사하면서 누를 수 있으면 cnt++
	while (target)
	{
		if (!button[target % 10])
			return 0;
		cnt += 1;
		target /= 10;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	memset(button, 1, sizeof(button));
	while (m--)
	{
		cin >> broken;
		button[broken] = 0;
	}
	int ret = abs(n - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		int x = i;
		int len = pressNum(x);
		if (len)
		{
			int press = abs(x - n);
			ret = min(ret, len + press);
		}
	}
	cout << ret;
}
