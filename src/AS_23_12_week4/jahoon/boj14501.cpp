#include <iostream>
#include <vector>
using namespace std;
// 퇴사
int main() {
	int n;
	cin >> n;
	vector<int> t(n, 0), p(n, 0), res(n+1, 0);
	for (int i=0; i<n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i=n-1; i>=0; i--){
		int deadline = i + t[i];
		if (deadline > n){
			res[i] = res[i+1];
		} else {
			res[i] = max(res[i+1], res[deadline] + p[i]);
		}
	}
	cout << res[0] << "\n";
}