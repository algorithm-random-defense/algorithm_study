/**
 * @file 17952.cpp
 * @author jiyeon
 * @brief 과제는 끝나지 않아!
 * @date 2024-01-08
 * 
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, answer = 0;
    stack<pair<int, int>> homework; // <점수, 남은 시간>

    cin >> n;
    for (int i = 0; i < n; i++) {
        int is_homework, score, time;
        // 입력 받기
        cin >> is_homework;
        if (is_homework) {
            cin >> score >> time;
            homework.push({score, time});
        }
        // 할 과제가 있다면 하기
        if (!homework.empty()) {
            homework.top().second -= 1;
            if (homework.top().second == 0) {
                answer += homework.top().first;
                homework.pop();
            }
        }
    }

    cout << answer << endl;

    return 0;
}