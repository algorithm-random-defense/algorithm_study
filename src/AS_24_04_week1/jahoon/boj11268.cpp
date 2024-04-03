#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
// 절댓값 힙
struct compare {
	bool operator()(long long a, long long b){
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, num;
	cin >> n;
	priority_queue<long long, vector<long long>, compare> pq;
	while (n--) {
		cin >> num;
		if (num) {
			pq.push(num);
		} else if (pq.empty()) {
			cout << "0\n";
		} else {
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}