// 1

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int input;

	while (cin >> input) { // 신기하네
		int one = 1, cnt = 1;

		while (true) {
			if (one % input == 0)
				break;
			else {
				cnt++;
				one = one * 10 + 1;
				one %= input;
			}
		}
		cout << cnt << '\n';
	}
}
// 실수로 머지해서 다시 올립니다..
