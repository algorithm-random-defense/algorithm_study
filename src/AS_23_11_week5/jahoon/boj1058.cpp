#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
// 친구
int main() {
	int n, answer=0;
	cin >> n;
	string input;
	unordered_map<int, vector<int>> um;
	set<int> friends;
	for (int i=0; i<n; i++) {
		cin >> input;
		for (int j=0; j<n; j++) {
			if (input[j]=='Y') {
				um[i].push_back(j);
			}
		}
	}
	for (auto u : um) {
		friends.clear();
		for (auto f : u.second) {
			friends.insert(f);
			for (auto ff : um[f]) {
				friends.insert(ff);
			}
		}
		answer = max(answer, (int)friends.size());
	}
	if (answer) answer--;
	cout << answer << "\n";

}