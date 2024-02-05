#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 후보 추천하기
vector<int> candi(101, 0);

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return candi[a.first] == candi[b.first] ? a.second < b.second : candi[a.first] < candi[b.first] ;
}

int main() {
	int n, t, num;
	cin >> n;
	vector<pair<int, int>> list;// 번호, 순서
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> num;
		if (candi[num]) {
			candi[num]++;
		} else if (list.size() == n) {
			candi[num]++;
			candi[list.front().first] = 0;
			list.front() = {num, i};
		} else {
			candi[num]++;
			list.push_back({num, i});
		}
		sort(list.begin(), list.end(), compare);
	}
	for (int i=1; i<=100; i++) {
		if (candi[i]) cout << i << " ";
	}
}