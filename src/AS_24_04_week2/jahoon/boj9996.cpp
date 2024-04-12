#include <iostream>
#include <string>
using namespace std;
//한국이 그리울 땐 서버에 접속하지
int main() {
	int n;
	string str, a, b;
	cin >> n;
	cin >> str;
	int idx = str.find('*');
	a = str.substr(0, idx);
	b = str.substr(idx + 1);
	while (n--) {
		cin >> str;
		if (str.size() < a.size() + b.size() ||
			str.substr(0, a.size()) != a ||
			str.substr(str.size() - b.size()) != b) {
			cout << "NE\n";
			continue;
		}
		cout << "DA\n";
	}
}