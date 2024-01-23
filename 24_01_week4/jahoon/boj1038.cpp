#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 감소하는 수
vector<long long> v;

void dfs(string s) {
	v.push_back(stoll(s));
	for (int i=0; i<=9; i++) {
		if (s.back() <= i + '0') {
			break;
		}
		dfs(s+to_string(i));
	}
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<=9; i++) {
		dfs(to_string(i));
	}
	sort(v.begin(), v.end());
	cout << (n >= 1023 ? -1 : v[n]) << "\n";
}