#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<string>& board, int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			board[i][j] = board[i][j] == '0' ? '1' : '0';
		}
	}
}
// 행렬
int main() {
	int n, m, answer = 0;
	cin >> n >> m;
	vector<string> board(n), target(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> target[i];
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (board[i][j] != target[i][j]) {
				reverse(board, i, j);
				answer++;
			}
		}
	}
	for (int i = 0; i < n && answer != -1; i++) {
		for (int j = 0; j < m && answer != -1; j++) {
			if (board[i][j] != target[i][j]) {
				answer = -1;
			}
		}
	}
	cout << answer;
}