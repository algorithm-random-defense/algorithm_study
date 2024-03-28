#include <iostream>
using namespace std;

// 팩토리얼5
int main() {
	int n;
	cin >> n;
	unsigned long long dp[n + 1]; dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] * i % 10000000000000;
		while (dp[i] % 10 == 0) {
			dp[i] /= 10;
		}
	}
	string res = to_string(dp[n] % 100000);
	while (res.size() < 5) {
		res = "0" + res;
	}
	cout << res;
}