/**
 * @file 18405.cpp
 * @author jiyeon
 * @brief 경쟁적 전염
 * @date 2024-01-31
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, k, s, x, y;
    vector<vector<pair<int, int>>> board; // <바이러스, 시간>
    queue<pair<int, int>> q;

    cin >> n >> k;
    board.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int virus; cin >> virus;
            board[i].push_back({virus, 0});
            if (virus != 0)
                q.push({i, j});
        }
    }
    cin >> s >> x >> y;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (board[x][y].second == s) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (board[nx][ny].first == 0
            || (board[nx][ny].first > board[x][y].first && board[nx][ny].second == board[x][y].second + 1)) {
                board[nx][ny].first = board[x][y].first;
                board[nx][ny].second = board[x][y].second + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << board[x - 1][y - 1].first << endl;

    return 0;
}