/**
 * @file 2698.cpp
 * @author jiyeon
 * @brief 인접한 비트의 개수
 * @date 2024-01-16
 * 
 */

#include <iostream>
using namespace std;

#define MAX 101

int main() {
    int t;
    cin >> t;

    int dp[MAX][MAX][2]; // n, k, bit
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for (int n = 2; n < MAX; n++) {
        for (int k = 0; k < n; k++) {
            // 0은 인접한 비트 개수에 영향을 주지 않으므로 n - 1일 때의 값과 동일
            dp[n][k][0] = dp[n - 1][k][0] + dp[n - 1][k][1];
            // 0 뒤에 오는 1은 개수에 영향을 주지 않음 : dp[n - 1][k][0]
            // 1 뒤에 오는 1은 개수에 영향을 주므로 n - 1, k - 1일 때 1로 끝나는 수열에 1을 붙여야 함 : dp[n - 1][k - 1][1]
            dp[n][k][1] = dp[n - 1][k][0] + dp[n - 1][k - 1][1];
        }
    }

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k][0] + dp[n][k][1] << endl;
    }

    return 0;
}
