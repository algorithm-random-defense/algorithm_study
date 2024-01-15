// DSLR
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int n, in, out;
bool Visit[10000];

int D(int n)
{
	return (n * 2) % 10000;
}

int S(int n)
{
	if (n == 0)
		return 9999;
	return n - 1;
}

int L(int n)
{
	return (n % 1000) * 10 + (n / 1000);
}

int R(int n)
{
	return (n % 10) * 1000 + (n / 10);
}

string func(int n)
{
	queue<pair<int, string> > q;
	q.push(make_pair(n, ""));
	memset(Visit, false, sizeof(Visit));
	Visit[n] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		string s = q.front().second;
		q.pop();
		if (x == out)
			return s;
		int nx = D(x);
		if (Visit[nx] == false)
		{
			Visit[nx] = true;
			q.push(make_pair(nx, s + "D"));
		}
		nx = S(x);
		if (Visit[nx] == false)
		{
			Visit[nx] = true;
			q.push(make_pair(nx, s + "S"));
		}
		nx = L(x);
		if (Visit[nx] == false)
		{
			Visit[nx] = true;
			q.push(make_pair(nx, s + "L"));
		}
		nx = R(x);
		if (Visit[nx] == false)
		{
			Visit[nx] = true;
			q.push(make_pair(nx, s + "R"));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--)
	{
		cin >> in >> out;
		string ans = func(in);
		cout << ans << endl;
	}
}
