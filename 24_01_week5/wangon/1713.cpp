#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, cnt;
vector<int> Time(101, 0);
vector<int> Vote(101, 0);

bool comp(const int a, const int b)
{
	if (Vote[a] == Vote[b])
	{
		if (Time[a] < Time[b])
			return true;
		else
			return false;
	}
	else if (Vote[a] > Vote[b])
		return true;
	else
		return false;
}

int main()
{
	vector<int> board;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> cnt;

	while (cnt--)
	{
		int candidate;
		cin >> candidate;
		Vote[candidate]++;
		if (find(board.begin(), board.end(), candidate) != board.end())
			continue;
		else
		{
			if (board.size() < n)
				board.push_back(candidate);
			else
			{
				sort(board.begin(), board.end(), comp);
				Vote[board.back()] = 0;
				Time[board.back()] = 0;
				board.back() = candidate;
			}
		}
		for (int i = 0; i < board.size(); i++)
			Time[board[i]]++;
	}
	sort(board.begin(), board.end());
	for (int i = 0; i < board.size(); i++)
		cout << board[i] << " ";
}
