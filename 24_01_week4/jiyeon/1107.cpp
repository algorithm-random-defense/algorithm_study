/**
 * @file 1107.cpp
 * @author jiyeon
 * @brief 리모컨
 * @date 2024-01-27
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<bool> broken(10, false);
 
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int button;
        cin >> button;
        broken[button] = true; // 고장난 버튼 처리
    }

    int answer = abs(n - 100); // 100번 채널에서 N으로 이동하는 경우
    for (int i = 0; i <= 1000000; i++) {
        string channel = to_string(i);
        bool possible = true;
        for (char digit : channel) {
            if (broken[digit - '0']) {
                possible = false;
                break;
            }
        }
        if (possible)
            answer = min(answer, abs(n - i) + static_cast<int>(channel.length()));
    }

    cout << answer << endl;

    return 0;
}
