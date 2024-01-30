#include <iostream>
using namespace std;
// 게임
int main() {
	long long x, y, z, a, b, answer;
	cin >> x >> y;
	z = (y * 100) / x;
	if (z + 1 >= 100) {
		cout << -1 << "\n";
		return 0;
	}
	a = (z+1)*x-100*y;
	b = 100-z-1;
	answer = a%b ? a/b+1 : a/b;
	cout << answer << "\n";
}

/*
z+1 = (y+cnt)*100 / (x+cnt)
(z+1)(x+cnt) = (y+cnt)*100
(z+1)x + (z+1)cnt = 100y + 100cnt;
(100-z-1)cnt = (z+1)x - 100y;
*/
