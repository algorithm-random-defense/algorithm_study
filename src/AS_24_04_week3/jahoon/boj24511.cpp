#include <iostream>
#include <deque>
using namespace std;
// queuestack
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, b, c;
	cin >> n;
	int a[n];
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (!a[i]) {
			dq.push_back(b);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> c;
		dq.push_front(c);
		cout << dq.back() << " ";
		dq.pop_back();
	}
}