#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, bot, op;
	cin >> n;
	int idx[6] = {5, 3, 4, 1, 2, 0};
	vector<vector<int> > arr(n);
	vector<int> sumArr(6, 0);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(6, 0);
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 6; i++)
	{
		vector<int> tmp_f(arr[0].begin(), arr[0].end());
		int first_bot = tmp_f[i];
		int first_op = tmp_f[idx[i]];
		tmp_f.erase(find(tmp_f.begin(), tmp_f.end(), first_bot));
		tmp_f.erase(find(tmp_f.begin(), tmp_f.end(), first_op));
		sumArr[i] = *max_element(tmp_f.begin(), tmp_f.end());
		op = first_op;
		for (int j = 1; j < n; j++)
		{
			vector<int> tmp(arr[j].begin(), arr[j].end());
			bot = op;
			int it = find(tmp.begin(), tmp.end(), bot) - tmp.begin();
			op = tmp[idx[it]];
			tmp.erase(find(tmp.begin(), tmp.end(), bot));
			tmp.erase(find(tmp.begin(), tmp.end(), op));
			int add = *max_element(tmp.begin(), tmp.end());
			sumArr[i] += add;
		}
	}
	int maxSum = *max_element(sumArr.begin(), sumArr.end());
	cout << maxSum << endl;
}
