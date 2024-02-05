// 공통 부분 문자열
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp[4001][4001];
int ret = 0;

void func(string s1, string s2)
{
	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j-1] + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	func(a, b);
	cout << ret;
}
