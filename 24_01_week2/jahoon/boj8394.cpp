#include <iostream>
#include <vector>
using namespace std;
// 악수
int main() {
	int n;
	cin >> n;
	vector<int> v(n+1, 0);
	v[2] = 2;
	v[3] = 3;
	for (int i=4; i< v.size(); i++) {
		v[i] = (v[i-1] + v[i-2]) % 10;
	}
	cout << v[n] << "\n";
}