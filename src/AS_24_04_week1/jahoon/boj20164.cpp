#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n, answerMax = 0, answerMin = INT32_MAX;
// 홀수 홀릭 호석
void dfs(string num, int cnt) {
	for (auto c : num) {
		if ((c - '0') % 2) cnt++;
	}
	if (num.size() == 1) {
		answerMax = max(answerMax, cnt);
		answerMin = min(answerMin, cnt);
		return ;
	}
	if (num.size() == 2) {
		dfs(to_string(num[0] + num[1] - 96), cnt);
		return ;
	}
	for (int i = 1; i < num.size() - 1; i++) {
		for (int j = 1; i + j < num.size(); j++) {
			int nextNum = stoi(num.substr(0, i)) + stoi(num.substr(i, j)) + stoi(num.substr(i + j));
			dfs(to_string(nextNum), cnt);
		}
	}
}

int main() {
	cin >> n;
	dfs(to_string(n), 0);
	cout <<  answerMin << " " << answerMax;
}