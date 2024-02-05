#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > arr(n, vector<int>(m));
	vector<vector<int> > dp(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
		dp[i][0] = arr[i][0] + dp[i - 1][0];
	for (int i = 1; i < m; i++)
		dp[0][i] = arr[0][i] + dp[0][i - 1];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
	}
	cout << dp[n - 1][m - 1] << endl;
}
