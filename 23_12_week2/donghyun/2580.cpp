// 스도쿠
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > board(9, vector<int>(9, 0));
vector<pair<int, int> > empty_xy;

// 0 1 2  3 4 5  6 7 8
void eraseInvalidNum(int x, int y, vector<bool>& bv) {
	int start_x = x / 3 * 3, start_y = y / 3 * 3;
	// 3 x 3 박스
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int n = board[start_x + i][start_y + j];
			bv[n] = false;
		}
	}
	// 가로
	for (int i = 0; i < 9; i++) {
		bv[board[i][y]] = false;
	}
	// 세로
	for (int i = 0; i < 9; i++) {
		bv[board[x][i]] = false;
	}
}

bool recur(int depth) {
	if (depth == empty_xy.size()) {
		return true;
	}
	vector<bool> bv(10, true);
	eraseInvalidNum(empty_xy[depth].first, empty_xy[depth].second, bv);
	for (int i = 1; i < 10; i++) {
		if (bv[i] == false)
			continue;
		board[empty_xy[depth].first][empty_xy[depth].second] = i;
		if (recur(depth + 1)) // 해결!
			return true;
		board[empty_xy[depth].first][empty_xy[depth].second] = 0;
	}
	return false; // 돌아가야함
}

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				empty_xy.push_back(make_pair(i, j));
		}
	}
	recur(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}
