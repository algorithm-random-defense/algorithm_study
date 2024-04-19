#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 최소비용 구하기

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, s, e, p;
	cin >> n >> m;
	vector<vector<pair<int, int>>> arr(n + 1);
	vector<int> cost(n + 1, INT32_MAX);
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> p;
		arr[s].push_back({e, p});
	}
	cin >> s >> e;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({s, 0});
	cost[s] = 0;
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (cur.second > cost[cur.first]) continue;// 시간초과 나고 안나고 차이
		for (auto& to : arr[cur.first]) {
			int curCost = cur.second + to.second;
			if (cost[to.first] > curCost) {
				cost[to.first] = curCost;
				pq.push({to.first, curCost});
			}
		}
	}
	cout << cost[e];
}