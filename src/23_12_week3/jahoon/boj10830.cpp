#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;
// 행렬 제곱
long long n, b;

vector<vector<long long>> mulVec(vector<vector<long long>> &a, vector<vector<long long>> &b) {
	vector<vector<long long>> res(n, vector<long long>(n, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000;
		}
	}
	return res;
}

int main() {
	cin >> n >> b;
	vector<vector<long long>> v(n, vector<long long>(n)), answer(n, vector<long long>(n, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==j) answer[i][j] = 1;
			cin >> v[i][j];
		}
	}
	string bits = bitset<64>(b).to_string();
	int maxPower = 64 - bits.find("1", 0);
	vector<vector<vector<long long>>> v_power(maxPower + 1, vector<vector<long long>>(n, vector<long long>(n, 0)));
	v_power[1] = v;
	for (int i=2; i<=maxPower; i++) {
		v_power[i] = mulVec
	(v_power[i-1], v_power[i-1]);
	}
	reverse(bits.begin(), bits.end());
	for (int i=0; i<maxPower; i++) {
		if (bits[i] == '1') {
			answer = mulVec
		(answer, v_power[i+1]);
		}
	}
	if (b == 0) {
		answer = v_power[0];
	}
	for (auto r : answer) {
		for (auto c : r) {
			cout << c << " ";
		}
		cout << "\n";
	}
}