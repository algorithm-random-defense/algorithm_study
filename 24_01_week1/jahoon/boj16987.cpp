#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 계란으로 계란치기
int n, answer;

void dfs(int idx, vector<vector<int>>& eggs) {
	if (idx == n) {
		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (eggs[i][0] <= 0) cnt++;
		}
		answer = max(answer, cnt);
		return ;
	}

	for (int i=0; i<n; i++) {
		if (idx == i) continue;
		if (eggs[idx][0] <= 0 || eggs[i][0] <= 0) {
			dfs(idx+1, eggs);
			continue;
		}
		eggs[idx][0] -= eggs[i][1];
		eggs[i][0] -= eggs[idx][1];
		dfs(idx+1, eggs);
		eggs[idx][0] += eggs[i][1];
		eggs[i][0] += eggs[idx][1];
	}
}

int main() {
	cin >> n;
	vector<vector<int>> eggs(n, vector<int>(2));
	for (int i=0; i<n; i++) {
		cin >> eggs[i][0] >> eggs[i][1];
	}
	dfs(0, eggs);
	cout << answer << "\n";
}

/*
3

102 250
28 140
247 111
*/