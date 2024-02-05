#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//알고스팟
int main() {
	int n, m;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	cin >> m >> n;
	vector<string> board(n);
	vector<vector<int>> vis(n, vector<int>(m, INT32_MAX));
	vis[0][0] = 0;
	for (int i=0; i<n; i++) {
		cin >> board[i];
	}
	deque<pair<int, int>> dq;
	dq.push_back({0, 0});
	while (!dq.empty()) {
		pair<int, int> cur = dq.front(); dq.pop_front();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
			int broken = vis[cur.first][cur.second] + board[nx][ny] - '0';
			if (vis[nx][ny] <= broken) continue;
			vis[nx][ny] = broken;
			dq.push_back({nx, ny});
		}
	}
	cout << vis[n-1][m-1] << "\n";
}