#include <iostream>
#include <vector>
using namespace std;
// 공통 부분 문자열
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int answer = 0;
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                answer = max(answer, dp[i][j]);
            }
        }
    }
    cout << answer << "\n";
}