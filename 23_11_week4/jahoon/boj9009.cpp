#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
// 피보나치
int main() {
	int t, num, size = 46;
	cin >> t;
	deque<int> fibo(size, 0);// 피보나치 수열
	fibo[1] = 1;
	for (int i=2; i<size; i++) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	while (t--) {
		cin >> num;
		deque<int> dq;
		while (num>0) {
			dq.push_front(*(upper_bound(fibo.begin(), fibo.end(), num)-1));// 피보나치 수열 중 해당 수보다 바로 작거나 같은 수로 빼준다.
			num -= dq.front();
		}
		for (auto d : dq) {
			cout << d << " ";
		}
		cout << "\n";
	}
}