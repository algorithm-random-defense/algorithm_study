#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long x, y, z;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y;
	z = y * 100 / x;
	if (z >= 99)
	{
		cout << "-1";
		return 0;
	}
	long long left = 0, right = 1000000000, mid, ret = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long tmp = (y + mid) * 100 / (x + mid);
		if (tmp > z)
		{
			ret = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ret;
}
