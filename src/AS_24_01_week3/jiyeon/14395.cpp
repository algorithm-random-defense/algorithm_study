/**
 * @file 14395.cpp
 * @author jiyeon
 * @brief 4연산
 * @date 2024-01-17
 * 
 */

#include <iostream>
#include <map>
#include <queue>
using namespace std;

int s, t;
queue<pair<long long, string>> q;
map<long long, int> visited;

void pushQueueIf(long long num, string command) {
    // 연산 결과가 1보다 작거나 이미 만든 적이 있는 수라면 리턴
    if (num < 1 || visited[num] > 1) return;
    visited[num]++;
    q.push({num, command});
}

void solution() {
    q.push({s, ""});
    while (!q.empty()) {
        long long num = q.front().first;
        string command = q.front().second;
        q.pop();
        // 찾았다 !
        if (num == t) { 
            cout << command << endl;
            return;
        }
        // 연산 순서: '*', '+', '-', '/'
        pushQueueIf(num * num, command + "*");
        pushQueueIf(num + num, command + "+");
        pushQueueIf(num - num, command + "-");
        pushQueueIf(num / num, command + "/");
    }
    cout << "-1" << endl;
}

int main() {
    cin >> s >> t;

    if (s == t) cout << "0" << endl;
    else solution();

    return 0;
}