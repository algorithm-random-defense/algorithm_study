#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;
// 추월
int main() {
	int n;
	cin >> n;
	int answer = n;
	string s;
	deque<string> dq;
	unordered_map<string, bool> um;
	for (int i = 0; i < n; i++) {
		cin >> s;
		dq.push_front(s);
	}
	while (!dq.empty()) {
		if (um[dq.back()]) {
			um[dq.back()] = false;
			dq.pop_back();
			continue;
		}
		cin >> s;
		if (dq.back() == s) {
			answer--;
			dq.pop_back();
		} else {
			um[s] = true;
		}
	}
	cout << answer;
}