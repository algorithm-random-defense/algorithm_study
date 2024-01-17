#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
long long s, t;
set<long long> arr;

string func()
{
	queue<pair<long long, string> > q;
	q.push(make_pair(s, ""));
	arr.insert(s);

	while (!q.empty())
	{
		long long x = q.front().first;
		string ret = q.front().second;
		q.pop();
		if (x == t)
			return ret;
		for (int i = 0; i < 4; i++)
		{
			long long nx;
			string ns;
			switch (i)
			{
			case 0:
				nx = x * x;
				ns = "*";
				break;
			case 1:
				nx = x + x;
				ns = "+";
				break;
			case 2:
				nx = x - x;
				ns = "-";
				break;
			default:
				nx = x / x;
				ns = "/";
			}
			if (nx < 1)
				continue;
			if (arr.find(nx) != arr.end())
				continue;
			arr.insert(nx);
			q.push(make_pair(nx, ret + ns));
		}
	}
	return "no";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	if (s == t)
	{
		cout << "0" << endl;
		return 0;
	}
	string ans = func();
	if (ans == "no")
		cout << "-1" << endl;
	else
		cout << ans << endl;
}
