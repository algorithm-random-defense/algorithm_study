#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 두 배 더하기
int main(void) {
	int n, cnt = 0;
	cin >> n;
	vector<int> arr(n);

	for (auto& i : arr) {
		cin >> i;
	}

	while (1) {
		int zero = 0;
		for (auto& i : arr) {
			if (i % 2) {
				cnt++;
				i--;
			}
			if (i == 0) {
				zero++;
			}
		}

		if (zero == n) {
			break;
		}

		cnt++;
		for (auto& i : arr) {
			i /= 2;
		}
	}

	cout << cnt << '\n';
	return 0;
}