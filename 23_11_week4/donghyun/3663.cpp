#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt, res; // 바꿔야 할 개수
vector<int> v;
string input;
bool vis[1010];

void dfs(int depth, int idx) {
	if (depth == v.size()) {
		res = min(cnt, res);
		return ;
	}
	// 왼쪽으로 갈 때
	int next_idx = idx;
	for (; next_idx >= 0; next_idx--) {

	}

	vis[next_idx] = true;

	vis[next_idx] = false;
	// 오른쪽으로 갈 때
	씨 ㅡ 바 못풀겠다
}


int solution() {
	cnt = 0;
	res = 2147483647;
	v.clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < input.size(); i++) {
		if (input[i] != 'A') {
			v.push_back(i);
			cnt += min(abs(input[i] - 'A'), abs('Z' + 1 - input[i]));
		}
	}
	dfs(0, 0);
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout << solution();
	}
}
