#include <iostream>
#include <set>
using namespace std;
// 숫자판 점프

set<string> res;
char board[5][5];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, string s) {
	if (s.size() == 6) {
		res.insert(s);
		return ;
	}
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		dfs(nx, ny, s + board[nx][ny]);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, string(1, board[i][j]));
		}
	}
	cout << res.size();
}