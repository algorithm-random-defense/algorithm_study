/**
 * @file 9019.cpp
 * @author jiyeon
 * @brief DSLR
 * @date 2024-01-11
 * 
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, string>> q; // <현재 수, 명령어>
bool visited[10000];

void pushQueueIf(int num, string command) {
    if (visited[num] == false) {
        visited[num] = true;
        q.push({num, command});
    }
}

void solution(int a, int b) {
    // 초기화
    while (!q.empty()) q.pop();
    memset(visited, 0, sizeof(visited));
    // 시작 값 넣어주기
    q.push({a, ""});
    visited[a] = 1;
    // bfs
    while (!q.empty()) {
        int num = q.front().first;
        string command = q.front().second;
        q.pop();
        if (num == b) { // 찾았다 !
            cout << command << endl;
            return;
        }

        pushQueueIf((2 * num) % 10000, command + "D");
        pushQueueIf(num == 0 ? 9999 : num - 1, command + "S");
        pushQueueIf((num * 10) % 10000 + num / 1000, command + "L");
        pushQueueIf(num / 10 + (num % 10) * 1000, command + "R");
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        solution(a, b);
    }

    return 0;
}