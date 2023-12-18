#include <iostream>
#include <vector>
using namespace std;

int n, m;
// 자원 캐기
int main() {
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m)), dp(n, vector<int>(m, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int up, left;
			up = i != 0 ? dp[i-1][j] : 0;
			left = j != 0 ? dp[i][j-1] : 0;
			dp[i][j] = board[i][j] + max(up, left);
		}
	}
	cout << dp[n-1][m-1];
}