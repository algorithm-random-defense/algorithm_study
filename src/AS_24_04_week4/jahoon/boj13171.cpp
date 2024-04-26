#include <iostream>
#include <bitset>
#include <algorithm>
#define DIV 1000000007
using namespace std;
// A
int main() {
	long long a, x, answer = 1;
	cin >> a >> x;
	long long dp[64];
	dp[0] = a;
	for (int i = 1; i < 64; i++) {
		dp[i] = ((dp[i - 1] % DIV) * (dp[i - 1] % DIV)) % DIV;
	}

	string s = bitset<64>(x).to_string();
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			answer = (answer * dp[i]) % DIV;
		}
	}
	cout << answer;
}