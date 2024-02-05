// 첫째 줄에 N과 M이 주어진다.
// N은 행의 개수이고, M은 열의 개수이다.N과 M은 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 N개의 줄에는 램프의 상태가 주어진다.1이 켜져있는 상태이고, 0이 꺼져있는 상태이다.마지막 줄에는 K가 주어진다.
// K는 1, 000보다 작거나 같은 자연수 또는 0이다.
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int n, m, k, cnt = 0;
int same[51], zero[51];
string table[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(same, 0, sizeof(same));
	memset(zero, 0, sizeof(zero));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> table[i];
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		string s = table[i];
		for (int j = 0; j < n; j++)
		{
			if (s == table[j])
				same[i]++;
		}
		for (int j = 0; j< m; j++)
		{
			if (s[j] == '0')
				zero[i]++;
		}
	}
	for (int i = 0; i< n; i++)
		if (zero[i] <= k && zero[i] % 2 == k % 2)
			cnt = max(cnt, same[i]);
	cout << cnt;
}
