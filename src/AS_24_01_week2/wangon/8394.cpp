// 악수
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
long long dp[10000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10;
	cout << dp[n];
}
