#include <iostream>
#include <vector>
using namespace std;
// 타일 코드
int main() {
	int n;
	cin >> n;
	vector<int> dp(31, 0), s(31, 0);
	dp[1] = 1; dp[2] = 3;
	for (int i=3; i<=30; i++) {
		dp[i] = dp[i-1] + 2 * dp[i-2];
	}
	s[1] = 1; s[2] = 3; s[3] = 1; s[4] = 5;
	for (int i=5; i<=30; i++) {
		s[i] = s[i-2] + 2 * s[i-4];
	}
    cout << (dp[n] - s[n]) / 2 + s[n];
}