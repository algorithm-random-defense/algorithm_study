#include <iostream>
#include <vector>
using namespace std;
// 4 연산
long long s, t;
string answer;

void dfs(long long cur, string res) {
	if ((res.size() >= answer.size() && answer != "") || cur > t) {
		return ;
	}
	if (cur == t) {
		answer = res;
		return ;
	}
	if (cur <= t / cur && cur != 1) {
		dfs(cur * cur, res + "*");
	}
	dfs(cur + cur, res + "+");
}

int main() {
	cin >> s >> t;
	if (s == t) {
		cout << 0 << "\n";
		return 0;
	}
	dfs(s, "");
	dfs(1, "/");
	if (answer == "") answer = "-1";
	cout << answer << "\n";
}