#include <iostream>
#include <vector>
#include <queue>
#define MAX 50000
using namespace std;

int n, m;
int dist[MAX + 1];
vector<pair<int, int>>v[MAX + 1];
// 택배 배송
void dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = INT32_MAX;
	priority_queue<pair<int, int>> pq;
	pq.push({start, 0});
	dist[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int newcost = v[cur][i].second + cost;
			if (dist[next] > newcost) {
				dist[next] = newcost;
				pq.push({next, -dist[next]});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	dijkstra(1);
	cout << dist[n];
}