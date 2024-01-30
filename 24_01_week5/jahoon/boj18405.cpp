#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// 경쟁적 전염
int main() {
	int n, k, s, x, y;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	cin >> n >> k;
	deque<vector<int>> dq, next;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				dq.push_back({board[i][j], i, j});
			}
		}
	}
	cin >> s >> x >> y;
	sort(dq.begin(), dq.end());
	while (s--) {
		next.clear();
		while (!dq.empty()) {
			vector<int> cur = dq.front(); dq.pop_front();
			for (int dir=0; dir<4; dir++) {
				int nx = cur[1] + dx[dir];
				int ny = cur[2] + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (board[nx][ny]) continue;
				next.push_back({cur[0], nx, ny});
				board[nx][ny] = cur[0];
			}
		}
		dq = next;
	}

	cout << board[x-1][y-1] << "\n";
}