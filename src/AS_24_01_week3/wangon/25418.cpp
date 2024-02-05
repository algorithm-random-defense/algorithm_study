#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int dp[1000001];
int a, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> k;
	dp[0] = 0;
	dp[1] = 0;
	for (int i = a + 1; i <= k; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && i / 2 >= a)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[k];
}
