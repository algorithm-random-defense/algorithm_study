#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);// 입출력이 많아서 넣어주면 좀 빨라진다.
	cin.tie(0);
	cout.tie(0);
	int n, k, answer=0;
	cin >> n >> k;
	vector<int> students(n), dist(n-1);
	for (int i=0; i<n ;i++) {
		cin >> students[i];
	}
	for (int i=0; i<n-1; i++) {
		dist[i] = students[i+1] - students[i];
	}
	sort(dist.begin(), dist.end());
	dist.erase(dist.end()-k+1, dist.end());
	for (auto d : dist) {
		answer += d;
	}
	cout << answer << "\n";
}