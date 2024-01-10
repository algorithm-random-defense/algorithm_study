#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 휴게소 세우기
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	vector <int> vec(n);

	vec.push_back(0); vec.push_back(l);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	int low = 1, high = l - 1, mid, result = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		int cnt = 0;
		for (int i = 1; i < vec.size(); i++) {
			int dist = vec[i] - vec[i-1];

			cnt += dist / mid;
			if (dist % mid == 0) cnt--;
		}
		if (cnt > m)
			low = mid + 1;
		else {
			high = mid - 1;
			result = mid;
		}
	}

	cout << result << endl;
}