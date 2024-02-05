#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T;
int dp[101][101][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i < 101; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}
	cin >> T;
	while (T--)
	{
		int n, k, cnt;
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << endl;
	}
}

