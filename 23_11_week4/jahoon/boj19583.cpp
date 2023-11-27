#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// 싸이버개강총회
int getTime(string s) {
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int main() {
	string input;
	int s, e, q, answer = 0;
	getline(cin, input);
	s = getTime(input.substr(0, 5));
	e = getTime(input.substr(6, 5));
	q = getTime(input.substr(12, 5));
	unordered_map<string, int> um;
	while (getline(cin, input)) {// eof 전까지 계속 받는다.
		int curTime = getTime(input.substr(0, 5));
		string name = input.substr(6);
		if (curTime > q) continue;
		if (curTime <= s && um[name] == 0) um[name]++;
		if (curTime >= e && um[name] == 1) um[name]++;
	}
	for (auto u : um) {
		if (u.second == 2) answer++;
	}
	cout << answer << "\n";
}

