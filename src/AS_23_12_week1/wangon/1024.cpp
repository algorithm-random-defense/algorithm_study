#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> func(int n, int l)
{
	for (int len = l; len <= 100; len++)
	{
		if ((n * 2) % len == 0)
		{
			int start = (2 * n - len * (len - 1)) / (2 * len);
			if (start >= 0)
			{
				vector<int> result;
				int sum = 0;
				for (int i = start; i < start + len; i++)
				{
					sum += i;
					result.push_back(i);
				}
				if (sum == n)
					return result;
			}
		}
	}
	return vector<int>();
}

int main()
{
	int n, l;
	cin >> n >> l;
	vector<int> ans = func(n, l);
	if (ans.empty())
	{
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
