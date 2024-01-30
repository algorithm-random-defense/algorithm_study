#include <iostream>
#include <vector>
using namespace std;
// 램프
int main() {
	int n, m, k, answer=0;
	cin >> n >> m;
	vector<string> board(n);
	for (int i=0; i<n; i++) {
		cin >> board[i];
	}
	cin >> k;

	for (int i=0; i<n; i++) {
		int cnt = 0;
		for (int j=0; j<m; j++) {
			if (board[i][j] == '0') cnt++;
		}
		if (cnt>k || cnt%2 != k%2) continue;
		int sameCnt=0;
		for (int j=0; j<n; j++) {
			if (board[i]==board[j]) sameCnt++;
		}
		answer = max(answer, sameCnt);
	}
	cout << answer << "\n";
}