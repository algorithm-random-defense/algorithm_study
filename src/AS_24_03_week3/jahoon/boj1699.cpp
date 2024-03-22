#include <iostream>
#include <cmath>

using namespace std;
// 제곱수의 합
int answer = INT32_MAX;

void dfs(int n, int mx, int cnt) {
	if (cnt >= answer || mx == 0) return;
	if (n == 0) {
		answer = cnt;
		return;
	}
	if (pow(mx, 2) <= n) {
		dfs(n - pow(mx, 2), mx, cnt + 1);
	}
	dfs(n, mx - 1, cnt);
}

int main() {
	int n;
	cin >> n;
	int mx = sqrt(n);
	dfs(n, mx, 0);
	cout << answer;
}
