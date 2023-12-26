// 타일링
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string dp[251];

string addNum(string a, string b)
{
	string ret;
	int carry = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
		{
			sum += a[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			sum += b[j] - '0';
			j--;
		}
		carry = sum / 10;
		ret = to_string(sum % 10) + ret;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = "1";
	dp[1] = "1";
	for (int i = 2; i <= 250; i++)
		dp[i] = addNum(dp[i - 1], (addNum(dp[i - 2], dp[i - 2])));
	int n;
	while (cin >> n)
		cout << dp[n] << endl;
}
