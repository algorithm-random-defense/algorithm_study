/**
 * @file 13164.cpp
 * @author jiyeon
 * @brief 행복 유치원
 * @date 2023-12-07
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, answer = 0;
    cin >> n >> k;

    vector<int> height(n), dist(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (i) dist[i - 1] = height[i] - height[i - 1]; // 인접한 사람의 키 차이 저장
    }

    sort(dist.begin(), dist.end());
    for (int i = 0; i < n - k; i++)
        answer += dist[i];

    cout << answer << endl;

    return 0;
}
