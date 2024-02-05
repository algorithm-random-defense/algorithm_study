#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, sum = 0, cnt_2 = 0;;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> tree(n);
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		sum += tree[i];
		cnt_2 += tree[i] / 2;
	}
	if (sum % 3 != 0)
		cout << "NO\n";
	else
	{
		if (cnt_2 >= sum / 3)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
