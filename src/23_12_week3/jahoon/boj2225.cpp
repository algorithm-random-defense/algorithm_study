#include <iostream>
#include <vector>
using namespace std;
// 합분해
int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
	for (int j=1; j<=k; j++) {
		dp[1][j] = j;
	}
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000000;
		}
	}
	cout << dp[n][k] << "\n";
}