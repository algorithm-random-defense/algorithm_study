#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 뱀과 사다리 게임
int main() {
	int n, m, from, to;
	cin >> n >> m;
	vector<int> board(101, 0), vis(101, 0);
	for (int i=1; i<=100; i++) {
		board[i] = i;
	}
	for (int i=0; i<n+m; i++) {
		cin >> from >> to;
		board[from] = to;
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i=1; i<=6; i++) {
			int next = board[cur + i];
			if (next>100) continue;
			if (vis[next] && vis[next] <= vis[cur] + 1) continue;
			q.push(next);
			vis[next] = vis[cur] + 1;
		}
	}
	cout << vis[100] << "\n";
}