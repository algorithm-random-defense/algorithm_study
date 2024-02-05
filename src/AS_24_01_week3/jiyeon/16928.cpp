/**
 * @file 16928.cpp
 * @author jiyeon
 * @brief 뱀과 사다리 게임
 * @date 2024-01-22
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    int board_info[101] = {0, };
    int visited[101] = {0, };

    cin >> n >> m;
    // 사다리, 뱀 정보 저장
    for (int i = 0; i < n + m; i++) {
        int from, to;
        cin >> from >> to;
        board_info[from] = to;
    }

    queue<pair<int, int>> q; // {현재 위치, 주사위 굴린 횟수}
    // 시작 지점
    q.push({1, 0});
    visited[1] = 1;
    // bfs
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) { // 주사위
            int next = cur + i;
            if (next == 100) {
                cout << cnt + 1 << endl;
                return 0;
            } else if (next > 100) {
                continue;
            }
            while (board_info[next]) // 사다리, 뱀
                next = board_info[next]; 
            if (visited[next] == 0) {
                visited[next] = 1;
                q.push({next, cnt + 1});
            }
        }
    }

    return 0;
}