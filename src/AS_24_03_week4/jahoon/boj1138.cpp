#include <iostream>
#include <vector>

using namespace std;
// 한 줄로 서기
int main() {
	int n, a;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < n; j++) {
			if (arr[j] == 0) {
				if (a == 0) {
					arr[j] = i + 1;
					break;
				}
				a--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}