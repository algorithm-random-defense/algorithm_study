#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m, answer=0;
	int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<bool>> vis(n, vector<bool>(m, false)), checkvis(n, vector<bool>(m, false));
	deque<pair<int,int>> dq;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!vis[i][j] && board[i][j]) {
				dq.clear(); dq.push_back({i, j});
				while (!dq.empty()) {
					pair<int, int> cur = dq.front(); dq.pop_front();
					for (int dir=0; dir<8; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
						if (board[nx][ny] > board[cur.first][cur.second] || vis[nx][ny]) continue;
						if (!board[nx][ny] || board[nx][ny] == board[i][j]) continue;
						vis[nx][ny] = true;
						dq.push_back({nx, ny});
					}
				}
			}
			if (!board[i][j]) vis[i][j] = true;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!vis[i][j] && !checkvis[i][j]) {
				answer++;
				dq.clear(); dq.push_back({i, j});
				while (!dq.empty()) {
					pair<int, int> cur = dq.front(); dq.pop_front();
					checkvis[cur.first][cur.second] = true;
					for (int dir=0; dir<8; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
						if (vis[nx][ny] || checkvis[nx][ny]) continue;
						dq.push_back({nx, ny});
					}
				}
			}
		}
	}
	cout << answer << "\n";
}