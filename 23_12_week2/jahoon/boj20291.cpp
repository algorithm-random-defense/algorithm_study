#include <iostream>
#include <string>
#include <map>
using namespace std;
//파일 정리
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<string, int> m;
	string input;
	for (int i=0; i<n; i++) {
		cin >> input;
		m[input.substr(input.find('.')+1)]++;
	}
	for (auto t : m) {
		cout << t.first << " " << t.second << "\n";
	}
}