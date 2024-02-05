#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > direct(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (c == 'Y')
				direct[i][j] = 1;
		}
	}
	vector<vector<int> > indirect = direct;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (i != j && direct[i][j] == 0)
				{
					if (direct[j][k] == 1 && direct[k][i] == 1)
						indirect[i][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int friends = 0;
		for (int j = 0; j < n; j++)
		{
			if (indirect[i][j] == 1)
				friends++;
		}
		ans = max(ans, friends);
	}
	cout << ans << endl;
	return 0;
}
