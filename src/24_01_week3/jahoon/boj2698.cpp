#include <iostream>
#include <vector>
using namespace std;
// 인접한 비트의 개수
int t, n, k;
int main() {
	cin >> t;
	vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(2, 0)));
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 2; i <=100; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = j > 0 ? dp[i - 1][j][0] + dp[i - 1][j - 1][1] : dp[i - 1][j][0];
		}
	}
	while (t--) {
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}
}