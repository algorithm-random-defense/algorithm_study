#include <iostream>
#include <vector>
using namespace std;
// 격자상의 경로
int main() {
	int n, m, k, answer;
	cin >> n >> m >> k;

	vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
	board[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}
	int x = k / m + (k % m ? 1 : 0), y = k % m ? k % m : m;
	answer = k ? board[x][y] * board[n - x + 1][m - y + 1] : board[n][m];
	cout << answer;
}