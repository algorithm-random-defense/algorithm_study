#include <iostream>
#include <vector>
using namespace std;

string res = "NO";

void dfs(string tmp, string& answer, int size, string choosed) {
	if (res == "YES" || size > answer.size() || answer.substr(0, size) != tmp) {
		return ;
	}
	if (tmp == answer && choosed != "100") {
		res = "YES";
		return ;
	}
	if (choosed == "") {
		dfs(tmp+"01", answer, size+2, "");
		dfs(tmp+"100", answer, size+3, "100");
	} else if (choosed == "100") {
		dfs(tmp+"1", answer, size+1, "1");
		dfs(tmp+"0", answer, size+1, "100");
	} else if (choosed == "1") {
		dfs(tmp+"1", answer, size+1, "1");
		dfs(tmp+"01", answer, size+2, "");
		dfs(tmp+"100", answer, size+3, "100");
	}
}

int main() {
	int t;
	cin >> t;
	string input, answer;

	while (t--) {
		cin >> input;
		dfs("", input, 0, "");
		cout << res << "\n";
		res = "NO";
	}
}