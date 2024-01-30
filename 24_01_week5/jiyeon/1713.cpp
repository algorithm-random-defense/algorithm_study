/**
 * @file 1713.cpp
 * @author jiyeon
 * @brief 후보 추천하기
 * @date 2024-01-30
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<pair<int, int>> frames; // <학생 번호, 추천 횟수>

bool isExistStudent(int student) {
    for (auto& frame : frames) {
        if (frame.first == student) {
            frame.second += 1;
            return true;
        }
    }
    return false;
}

void eraseStudent() {
    int min = 1001, idx;
    for (int i = 0; i < n; i++) {
        if (frames[i].second < min) {
            min = frames[i].second;
            idx = i;
        }
    }
    frames.erase(frames.begin() + idx);
}

int main() {
    cin >> n >> cnt;

    while (cnt--) {
        int student; cin >> student;
        if (isExistStudent(student)) continue;
        if (frames.size() == n) eraseStudent();
        frames.push_back({student, 1});
    }

    vector<int> answer;
    for (auto frame : frames) answer.push_back(frame.first);
    sort(answer.begin(), answer.end());
    for (auto n : answer) cout << n << " ";
    cout << endl;

    return 0;
}