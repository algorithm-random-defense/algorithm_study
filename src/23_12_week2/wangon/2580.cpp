#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[9][9];
vector<pair<int, int> > blanks;
int cnt = 0;
bool endFlag = false;

bool check(pair<int, int> p)
{
	int checkX = p.first / 3;
	int checkY = p.second / 3;
	for (int i = 0; i < 9; i++)
	{
		if (arr[p.first][i] == arr[p.first][p.second] && i != p.second)
			return (false);
		if (arr[i][p.second] == arr[p.first][p.second] && i != p.first)
			return (false);
	}
	for (int i = checkX * 3; i < 3 * checkX + 3; i++)
		for (int j = checkY * 3; j < 3 * checkY + 3; j++)
		{
			if (arr[i][j] == arr[p.first][p.second])
			{
				if (i != p.first && j != p.second)
					return (false);
			}
		}
	return (true);
}

void func(int k)
{
	if (k == cnt)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << ' ';
			cout << endl;
		}
		endFlag = true;
		return;
	}
	for (int j = 1; j <= 9; j++)
	{
		arr[blanks[k].first][blanks[k].second] = j;
		if (check(blanks[k]))
			func(k+1);
		if (endFlag)
			return ;
	}
	arr[blanks[k].first][blanks[k].second] = 0;
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	pair<int, int> blank;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				cnt++;
				blank.first = i;
				blank.second = j;
				blanks.push_back(blank);
			}
		}
	}
	func(0);
}
