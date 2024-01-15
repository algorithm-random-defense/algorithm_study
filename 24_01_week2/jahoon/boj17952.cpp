#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 과제는 끝나지 않아!
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, info, a, t, res = 0;
	stack<pair<int, int>> st;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> info;
		if (info) {
			cin >> a >> t;
			st.push({a, t});
		}
		if (!st.empty() && !(--st.top().second)) {
			res += st.top().first;
			st.pop();
		}
	}
	cout << res << "\n";
}