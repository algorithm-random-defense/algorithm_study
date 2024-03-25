#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// 여러분의 다리가 되어 드리겠습니다!
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b, idx = 0;
	cin >> n;
	if (n == 2) {
		cout << "1 2";
		return 0;
	}
	vector<vector<int>> arr(n + 1);
	vector<int> vis(n+1, 0);
	deque<int> dq;
	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i].size() && !vis[i]) {
			vis[i] = ++idx;
			dq.push_back(i);
			while (!dq.empty()) {
				int from = dq.front();
				dq.pop_front();
				for (auto to : arr[from]) {
					if (vis[to]) continue;
					dq.push_back(to);
					vis[to] = idx;
				}
			}
		}
	}
	int from = find(vis.begin() + 1, vis.end(), idx - 1) - vis.begin();
	int to = find(vis.begin() + 1, vis.end(), idx) - vis.begin();
	cout << from << " " << to;
}