#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> res;
int n, m, answer = -1;

void getNums(int x, int y, int dx, int dy, vector<string>& board) {
	string num;
	if (!dx && !dy) {
		res.push_back(board[x][y]-'0');
		return ;
	}
	for (int i=x, j=y; 0<=i&&i<n&&0<=j&&j<m; i+=dx, j+=dy) {
		num += board[i][j];
		res.push_back(stoi(num));
	}
}

int main() {
	cin >> n >> m;
	vector<string> board(n);
	for (int i=0; i<n; i++) {
		cin >> board[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int dx=-i; dx<n-i; dx++) {
				for (int dy=-j; dy<m-j; dy++) {
					getNums(i, j, dx, dy, board);
				}
			}
		}
	}
	sort(res.begin(), res.end(), greater<int>());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto r : res) {
		int sq = sqrt(r);
		if (sq*sq==r) {
			answer = r;
			break ;
		}
	}
	cout << answer << "\n";
}