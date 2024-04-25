#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;
// 겹치는 건 싫어
int main () {
	int n, k, answer = 0, input;
	cin >> n >> k;
	vector<int> vis(100001, 0);
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> input;
		vis[input]++;
		dq.push_back(input);
		while (vis[input] > k) {
			vis[dq.front()]--;
			dq.pop_front();
		}
		answer = max(answer, (int)dq.size());
	}

	cout << answer;
}