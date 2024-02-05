#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 로봇 시뮬레이션

int main() {
	int a, b, n, m, x, y;
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	cin >> a >> b >> n >> m;
	vector<vector<int>> board(b, vector<int>(a, 0));
	unordered_map<int, pair<int, int>> pos;
	unordered_map<int, int> dirs;
	unordered_map<char, int> nesw = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
	for (int i=1; i<=n; i++) {
		char dir;
		cin >> x >> y >> dir;
		board[y-1][x-1] = i;
		pos[i] = {y-1, x-1};
		dirs[i] = nesw[dir];
	}

	while (m--) {
		int target, repeat;
		char command;
		cin >> target >> command >> repeat;
		int curX = pos[target].first, curY = pos[target].second, curDir = dirs[board[curX][curY]];
		while (repeat--) {
			if (command == 'L') {
				dirs[board[curX][curY]] = (dirs[board[curX][curY]] + 3) % 4;
			} else if (command == 'R') {
				dirs[board[curX][curY]] = (dirs[board[curX][curY]] + 1) % 4;
			} else {
				int nx = curX + dx[curDir];
				int ny = curY + dy[curDir];
				if (nx<0 || ny<0 || nx >= b || ny >= a) {
					cout << "Robot " << target << " crashes into the wall\n";
					return 0;
				}
				if (board[nx][ny]) {
					cout << "Robot " << target << " crashes into robot " << board[nx][ny] << "\n";
					return 0;
				}
				board[curX][curY] = 0;
				curX = nx; curY = ny;
				board[curX][curY] = target;
				pos[target] = {curX, curY};
			}
		}
	}
	cout << "OK\n";
}