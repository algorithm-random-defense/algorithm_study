#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 소가 길을 건너간 이유 5
int main() {
	int n, k, b, num, answer, fix = 0;
	cin >> n >> k >> b;
	vector<bool> light(n+1, true);
	for (int i=0; i<b; i++) {
		cin >> num;
		light[num] = false;
	}
	for (int i=1; i<=k; i++) {
		if (!light[i]) fix++;
	}
	answer = fix;
	for (int i=k+1; i<=n; i++) {
		if (!light[i-k]) fix--;
		if (!light[i]) fix++;
		answer = min(answer, fix);
	}
	cout << answer << "\n";
}