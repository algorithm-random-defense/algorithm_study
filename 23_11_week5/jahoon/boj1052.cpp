#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
// 물병
int main() {
	int n, k, answer = -1;
	cin >> n >> k;
	int cur = n;
	while (1) {
		if (bitset<32>(cur).count()<=k) {
			answer = cur - n;
			break;
		}
		cur++;
	}
	cout << answer << "\n";
}