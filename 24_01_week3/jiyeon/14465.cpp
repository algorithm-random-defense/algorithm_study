/**
 * @file 14465.cpp
 * @author jiyeon
 * @brief 소가 길을 건너간 이유 5
 * @date 2024-01-19
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> stoplight(n, 1);
    while (b--) {
        int idx;
        cin >> idx;
        stoplight[idx - 1] = 0; // 고장
    }

    int start = 0, answer = n;
    while (start + k <= n) {
        int cnt = 0;
        // 길이가 k인 구간에서 고장난 신호등 개수 찾기
        for (int idx = start; idx < start + k; idx++) {
            if (stoplight[idx] == 0)
                cnt++;
        }
        answer = min(answer, cnt);
        start++;
    }

    cout << answer << endl;

    return 0;
}
