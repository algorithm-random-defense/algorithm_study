/**
 * @file 19583.cpp
 * @author jiyeon
 * @brief 싸이버개강총회
 * @date 2023-11-22
 * 
 */

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    string start, end, quit;
    cin >> start >> end >> quit;

    string time, nickname;
    unordered_set<string> participant, answer;
    while (getline(cin, time, ' ') && getline(cin, nickname)) {

        if (time <= start) { // 개강총회를 시작하기 전
            participant.insert(nickname);
        } else if (time >= end && time <= quit) { // 개강총회를 끝내고 나서, 스트리밍을 끝낼 때까지
            if (participant.find(nickname) != participant.end())
                answer.insert(nickname);
        }
    }

    cout << answer.size() << endl;
    return 0;
}