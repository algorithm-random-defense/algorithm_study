#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> answer;
int n;
void dfs(int last_num, long long res) {
	answer.push_back(res*10+last_num);
	for (int i=0; i<last_num; i++) {
		dfs(i, res*10+last_num);
	}
}

int main() {
	cin >> n;
	if (n > 1023) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i=0; i<=9; i++) {
		dfs(i, 0);
	}
	sort(answer.begin(), answer.end());
	cout << answer[n-1] << "\n";
}