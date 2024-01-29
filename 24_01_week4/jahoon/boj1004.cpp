#include <iostream>
#include <cmath>
using namespace std;
// 어린 왕자
int t, s_x, s_y, e_x, e_y, n, c_x, c_y, c_r;

bool inOrOut(int x, int y) {
	return pow(abs(x - c_x), 2) + pow(abs(y - c_y), 2) < pow(c_r, 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--) {
		int answer = 0;
		cin >> s_x >> s_y >> e_x >> e_y;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> c_x >> c_y >> c_r;
			if (inOrOut(s_x, s_y) ^ inOrOut(e_x, e_y)) answer++;
		}
		cout << answer << "\n";
	}
}