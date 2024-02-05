/**
 * @file 5582.cpp
 * @author jiyeon
 * @brief 공통 부분 문자열
 * @date 2024-01-12
 * 
 */

#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int answer = 0;

    string a, b;
    cin >> a >> b;

    int dp[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof(dp));
    
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) { // 같은 부분 만나면 부분 문자열 찾기
                dp[i + 1][j + 1] = dp[i][j] + 1;
                answer = max(answer, dp[i + 1][j + 1]);
            }
        }
    }

    cout << answer << endl;

    return 0;
}