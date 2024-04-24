#include <iostream>
#include <algorithm>
using namespace std;
// 큰 수 A+B (2)
int main() {
	string a, b, res;
	res.reserve(10002);
	cin >> a >> b;
	int aIdx = a.size() - 1, bIdx = b.size() - 1, flag = 0;
	while (aIdx >= 0 || bIdx >= 0 || flag) {
		int num = flag;
		num = aIdx >= 0 ? num + a[aIdx--] - '0' : num;
		num = bIdx >= 0 ? num + b[bIdx--] - '0' : num;
		flag = num / 10;
		num %= 10;
		res.push_back(num + '0');
	}
	reverse(res.begin(), res.end());
	cout << res;
}