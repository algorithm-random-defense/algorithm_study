#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 알고리즘 수업 - 깊이 우선 탐색 2
int n, m, r,  u, v, idx;

void dfs(int next, vector<int>& vis, vector<vector<int>>& nodes) {
	for (auto& target : nodes[next]) {
		if (!vis[target]) {
			vis[target] = ++idx;
			dfs(target, vis, nodes);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	vector<vector<int>> nodes(n+1);
	vector<int> vis(n+1, 0);
	for (int i=0; i<m; i++) {
		cin >> u >> v;
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}
	for (auto& node : nodes) {
		sort(node.begin(), node.end(), greater<int>());
	}
	vis[r] = ++idx;
	dfs(r, vis, nodes);
	for (int i=1; i<=n; i++) {
		cout << vis[i] << "\n";
	}
}
