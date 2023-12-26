// 카드 놓기
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. 맨위
// 2. 맨위에서 두번째
// 3. 맨 아래

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> input(n);
	deque<int> dq;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	int num = 1;
	while (input.size())
	{
		switch (input[n - num])
		{
		case 1:
			dq.push_front(num);
			break;
		case 2:
			dq.insert(dq.begin() + 1, num);
			break;
		default:
			dq.push_back(num);
			break;
		};
		num++;
		input.pop_back();
	}
	for (int i = 0; i < n; i++)
		cout << dq[i] << ' ';
}
