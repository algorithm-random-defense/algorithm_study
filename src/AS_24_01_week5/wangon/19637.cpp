// If문좀 대신 써줘
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, string> title;
	int n, m, target;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		int score;
		cin >> s >> score;
		title.insert(make_pair(score, s));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> target;
		cout << title.lower_bound(target)->second << '\n';
	}
}
