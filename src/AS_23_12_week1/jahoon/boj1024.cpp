#include <iostream>
#include <vector>
using namespace std;
// 수열의 합
int main() {
	int n, l, s=-1;
	cin >> n >> l;
	vector<int> answer;
	while (l <= 100) {
		if (l%2 && n%l==0) {
			s = n/l - l/2;
			break;
		}
		if (!(l%2) && n%l == l/2) {
			s = n/l - l/2 + 1;
			break;
		}
		l++;
	}
	if (s < 0) {
		cout << -1 << "\n";
	} else {
		for (int i=0; i<l; i++) {
			cout << s + i << " ";
		}
		cout << "\n";
	}
}

/*

6 3// 1 2 3

10/// 1 2 3 4 => 2 2 2 2

99 3// 32 33 34

100 5// 18 19 20 21 22

45 10// 4 4 4 4 4 5 5 5 5 5

*/