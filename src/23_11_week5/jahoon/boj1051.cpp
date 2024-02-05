#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
// 숫자 정사각형
int main() {
	int n, m, answer=0;
	cin >> n >> m;
	vector<string> board(n);
	for (int i=0; i<n; i++) {
		cin >> board[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int len=min(n-i-1, m-j-1); len > answer; len--) {
				if (board[i][j] == board[i+len][j] && board[i][j] == board[i][j+len] && board[i][j] == board[i+len][j+len]) {
					answer = len;
					break ;
				}
			}
		}
	}
	cout << pow(answer+1, 2) << "\n";
}