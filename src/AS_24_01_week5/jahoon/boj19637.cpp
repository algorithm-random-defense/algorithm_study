#include <iostream>
#include <vector>
using namespace std;
// IF문 좀 대신 써줘
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, limit;
	string style;
	vector<int> limits(1);
	vector<string> styles(1), answer;

	cin >> n >> m;
	cin >> styles[0] >> limits[0];
	for (int i=1; i<n; i++) {
		cin >> style >> limit;
		if (limit == limits[i-1]) continue;
		limits.push_back(limit);
		styles.push_back(style);
	}

	for (int j=0; j<m; j++) {
		cin >> limit;
		int idx = lower_bound(limits.begin(), limits.end(), limit) - limits.begin();
		answer.push_back(styles[idx]);
	}

	for (auto s : answer) {
		cout << s << "\n";
	}
}