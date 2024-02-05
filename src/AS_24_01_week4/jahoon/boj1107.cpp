#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 리모컨
int n, m, num, answer, n_size;
vector<bool> broken(10, false);
void dfs(int cnt, int res) {
	if (cnt) answer = min(answer, abs(res - n) + cnt);
	if (cnt > n_size) return;
	for (int i=0; i<=9; i++) {
		if (!broken[i]) dfs(cnt + 1, res * 10 + i);
	}
}

int main() {
	cin >> n >> m;
	answer = abs(n - 100);
	n_size = to_string(n).size();
	for (int i=0; i<m; i++) {
		cin >> num;
		broken[num] = true;
	}
	dfs(0, 0);
	cout << answer << "\n";
}