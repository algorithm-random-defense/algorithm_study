//타일 코드
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] += dp[i - 1]; // 홀수일때
		dp[i] += dp[i - 2] * 2; // 짝수일때 좌우대칭
	}
	if (n % 2)
		cout << (dp[n] + dp[n / 2]) / 2 << endl;
	else
		cout << (dp[n] + dp[n / 2] + 2 * dp[n / 2 - 1]) / 2 << endl;
}
