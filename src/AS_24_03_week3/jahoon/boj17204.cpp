#include <iostream>
using namespace std;

// 죽음의 게임
int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	bool vis[n];
	fill(vis, vis + n, false);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int next = 0, cnt = 1;
	while (!vis[next] && arr[next] != k) {
		vis[next] = true;
		cnt++;
		next = arr[next];
	}
	cout << (arr[next] == k ? cnt : -1);
}