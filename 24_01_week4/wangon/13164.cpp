#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int n;
vector<string> nb;
queue<string> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (long long i = 0; i <= 9; i++)
	{
		nb.push_back(to_string(i));
		q.push(to_string(i));
	}
	while (!q.empty())
	{
		string x = q.front();
		q.pop();
		int idx = x.back() - '0';
		for (int i = 0; i < idx; i++)
		{
			string nx = x + to_string(i);
			nb.push_back(nx);
			q.push(nx);
		}
	}
	if (n >= nb.size())
		cout << "-1";
	else
		cout << nb[n];
}
