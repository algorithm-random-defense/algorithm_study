#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 주사위 쌓기
vector<int> opposite = {5, 3, 4, 1, 2, 0};

int getMaxSide(int d, int u) {
	for (int i=6; i>0; i--) {
		if (i != d && i != u) return i;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> dices(n, vector<int>(6)), dp(n, vector<int>(6, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<6; j++) {
			cin >> dices[i][j];
		}
	}
	for (int i=0; i<6; i++) {
		dp[0][i] = getMaxSide(dices[0][i], dices[0][opposite[i]]);
	}
	for (int j=0; j<6; j++) {
		int down = j;
		for (int i=1; i<n; i++) {
			down = find(dices[i].begin(), dices[i].end(), dices[i-1][opposite[down]]) - dices[i].begin();
			dp[i][j] = dp[i-1][j] + getMaxSide(dices[i][down], dices[i][opposite[down]]);
		}
	}

	cout << *max_element(dp[n-1].begin(), dp[n-1].end());
}