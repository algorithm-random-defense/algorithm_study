/**
 * @file 1004.cpp
 * @author jiyeon
 * @brief 어린 왕자
 * @date 2024-01-22
 * 
 */

#include <cmath>
#include <iostream>
using namespace std;

// gpt가 짜줌
bool checkInclude(int x, int y, int r, int target_x, int target_y) {
    double distance = sqrt(pow(target_x - x, 2) + pow(target_y - y, 2));
    return distance < r; // 경계에 걸치는 입력 없음
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        int from_x, from_y, to_x, to_y;
        cin >> from_x >> from_y >> to_x >> to_y >> n;

        int answer = 0, x, y, r;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            // 출발점 또는 도착점 중 하나를 포함할 때만 ++
            if (checkInclude(x, y, r, from_x, from_y)
                != checkInclude(x, y, r, to_x, to_y))
                answer++;
        }
        cout << answer << endl;
    }

    return 0;
}