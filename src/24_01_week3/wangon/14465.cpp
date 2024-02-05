#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> b;
	vector<int> light(100001, 1);
	while (b--)
	{
		int broken;
		cin >> broken;
		light[broken]--;
	}
	for (int i = 2; i <= n; i++)
		light[i] += light[i - 1];
	int maxSum = 0;
	for (int i = k; i <= n; i++)
		maxSum = max(maxSum, light[i] - light[i - k]);
	cout << k - maxSum;
}
