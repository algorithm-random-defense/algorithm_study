#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
// 정수 a를 k로 만들기
int main() {
	int a, k;
	cin >> a >> k;
	vector<int> vis(k + 1, -1);
	queue<int> q;
	q.push(a);
	vis[a] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int a = cur + 1, b = cur * 2;
		if (a <= k && (vis[cur] + 1 < vis[a] || vis[a] == -1)) {
			vis[a] = vis[cur] + 1;
			q.push(a);
		}
		if (b <= k && (vis[cur] + 1 < vis[b] || vis[b] == -1)) {
			vis[b] = vis[cur] + 1;
			q.push(b);
		}
	}
	cout << vis[k] << "\n";
}