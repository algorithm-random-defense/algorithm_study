/**
 * @file 1245.cpp
 * @author jiyeon
 * @brief 농장 관리
 * @date 2023-12-08
 * 
 */

#include <iostream>
#include <queue>
using namespace std;


int n, m, answer = 0;
int mountain[103][73], check[103][73];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
queue<pair<int, int> > q;

void find_top_bfs(int start_x, int start_y) {
    q.push({start_x, start_y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1)
                continue;
            if (check[nx][ny] // 아직 방문한 적 없는데
            && (mountain[x][y] > mountain[nx][ny] // 인접한 격자보다 작거나
            || (mountain[x][y] == mountain[nx][ny] && check[x][y] == 0))) { // 같은데 그것이 산봉우리가 아닐 때
                check[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}

void count_top_bfs(int start_x, int start_y) {
    answer++;
    check[start_x][start_y] = 0;
    q.push({start_x, start_y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            if (check[nx][ny]) {
                check[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1) // 가생이
                mountain[i][j] = 0;
            else
                cin >> mountain[i][j];
            check[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            find_top_bfs(i, j);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j] == 1)
                count_top_bfs(i, j);
        }
    }

    cout << answer << endl;

    return 0;
}