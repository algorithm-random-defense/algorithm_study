#include <iostream>
#include <vector>
using namespace std;
// 피보나치는 지겨웡~
int main() {
	int n;
	vector<int> dp(51, 1);
	cin >> n;
	for (int i=2; i<=50; i++) {
		dp[i] = (dp[i-2] + dp[i-1] + 1) % 1000000007;
	}
	cout << dp[n] << "\n";
}