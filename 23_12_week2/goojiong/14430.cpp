/**
 * @file 14430.cpp
 * @author jiyeon
 * @brief 자원 캐기
 * @date 2023-12-13
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int area[302][302], dp[302][302];
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> area[i][j];
    }

    dp[0][0] = area[0][0];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + area[i][0];
    for (int j = 1; j < m; j++) dp[0][j] = dp[0][j - 1] + area[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + area[i][j];
    }

    cout << dp[n - 1][m - 1] << endl;;

    return 0;
}