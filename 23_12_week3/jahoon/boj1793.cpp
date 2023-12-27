#include <iostream>
#include <vector>
using namespace std;
// 타일링
string sum(string a, string b) {
	string res = "";
	int a_idx = a.size() - 1, b_idx = b.size() - 1, round_up = 0;
	while (b_idx >= 0) {
		int digit_sum = a_idx >= 0 ? a[a_idx] + b[b_idx] + round_up - '0' * 2 : b[b_idx] + round_up - '0';
		round_up = digit_sum >= 10 ? 1 : 0;
		res = to_string(digit_sum % 10) + res;
		a_idx--;
		b_idx--;
	}
	return round_up ? "1" + res : res;
}

int main() {
	int n;
	vector<string> dp(251, "1");
	for (int i=2; i<=250; i++) {
		dp[i] = sum(dp[i-1], sum(dp[i-2], dp[i-2]));
	}
	while (cin >> n) {
		cout << dp[n] << "\n";
	}
}
