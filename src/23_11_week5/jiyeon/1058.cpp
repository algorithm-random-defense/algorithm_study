/**
 * @file 1058.cpp
 * @author jiyeon
 * @brief 친구
 * @date 2023-12-03
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int n, answer = 0;
    vector<int> friends[51];

    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            if (input[j] == 'Y') { // 친구이면 인접리스트에 추가
                friends[i].push_back(j);
                friends[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        queue<int> q;
        bool visited[51] = {0, };
        int cnt = 0;
        visited[i] = true; // 자기 자신 체크
        // 직접 친구
        for(int person: friends[i]) {
            if (visited[person] == false) {
                visited[person] = true;
                cnt++;
                q.push(person); // 친구의 친구 확인할라고
            }
        }
        // 친구의 친구
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int person: friends[cur]) {
                if (visited[person] == false) {
                    visited[person] = true;
                    cnt++;
                }
            }
        }

        answer = max(cnt, answer);
    }

    cout << answer << endl;

    return 0;
}