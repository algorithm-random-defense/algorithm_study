#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<string, int>& a, pair<string, int>& b) {
		return a.second > b.second;
	}
};
// 수강신청
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k, l, idx = 1;
	string input;
	cin >> k >> l;
	unordered_map<string, int> um;
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
	while (l--) {
		cin >> input;
		um[input] = idx++;
	}
	for (auto u : um) {
		pq.push({u.first, u.second});
	}
	while (k-- && !pq.empty()) {
		cout << pq.top().first << "\n";
		pq.pop();
	}
}