#include <iostream>
#include <vector>
using namespace std;
// 근손실
int n, k, answer;
vector<int> training(8);
vector<bool> done(8, false);

void dfs(int cnt, int weight) {
	if (weight < 500) {
		return ;
	}
	if (cnt == n) {
		answer++;
		return ;
	}
	for (int i=0; i<n; i++) {
		if (done[i]) continue;
		done[i] = true;
		dfs(cnt + 1, weight + training[i] - k);
		done[i] = false;
	}
}

int main() {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> training[i];
	}
	dfs(0, 500);
	cout << answer << "\n";
}