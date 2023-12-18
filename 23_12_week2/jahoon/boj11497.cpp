#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 통나무 건너뛰기
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		int answer = 0;
		cin >> n;
		vector<int> logs(n);
		for (int i=0; i<n; i++) {
			cin >> logs[i];
		}
		sort(logs.begin(), logs.end());
		for (int i=0; i<n-2; i++) {
			answer = max(answer, logs[i+2]-logs[i]);
		}
		cout << answer << "\n";
	}
}