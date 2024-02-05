/**
 * @file 17175.cpp
 * @author jiyeon
 * @brief 피보나치는 지겨웡~
 * @date 2023-12-10
 * 
 */

#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    vector<int> dp(51, 1); // dp[0] = 1, dp[1] = 1
    cin >> n;

    for (int i = 2; i < 51; i++)
        dp[i] = (dp[i - 2] + dp[i - 1] + 1) % 1000000007; // 1 : 자기 자신 호출

    cout << dp[n] << endl;

    return 0;
}