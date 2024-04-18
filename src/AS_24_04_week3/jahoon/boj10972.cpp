#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 다음 순열
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> cmp(arr);
	sort(cmp.begin(), cmp.end(), greater<>());
	for (int i = 0; i < n; i++) {
		if (arr[i] != cmp[i]) {
			next_permutation(arr.begin(), arr.end());
			for (auto a : arr) {
				cout << a << " ";
			}
			return 0;
		}
	}
	cout << -1;
}