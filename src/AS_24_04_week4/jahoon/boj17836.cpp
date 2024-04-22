#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
// 공주님을 구해라!
int main() {
	int n, m, t;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	cin >> n >> m >> t;
	vector<string> board(n, string(m, 0));
	vector<vector<int>> vis(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	deque<pair<int, int>> dq = {{0, 0}};
	vis[0][0] = 0;
	vis[n - 1][m - 1] = INT32_MAX;
	while (!dq.empty()) {
		pair<int, int> cur = dq.front();
		dq.pop_front();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '1') continue;
			if (vis[nx][ny] > 0 && vis[cur.first][cur.second] + 1 >= vis[nx][ny]) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			if (board[nx][ny] == '2') {
				vis[n - 1][m - 1] = min(vis[n - 1][m - 1], vis[nx][ny] + (n - nx) + (m - ny) - 2);
				continue;
			}
			dq.push_back({nx, ny});
		}
	}
	if (vis[n - 1][m - 1] != INT32_MAX && vis[n - 1][m - 1] <= t) {
		cout << vis[n - 1][m - 1];
	} else {
		cout << "Fail";
	}
}