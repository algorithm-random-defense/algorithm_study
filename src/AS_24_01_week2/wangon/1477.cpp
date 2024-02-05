// 휴게소 세우기
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
int n, m, l;
vector<int> road;
int ret = 0;

bool func(int mid)
{
	int cnt = 0;
	for (int i = 1; i < road.size(); i++)
	{
		int distance = road[i] - road[i - 1];
		cnt += distance / mid;
		if (distance % mid == 0)
			cnt--;
	}
	return cnt > m;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> l;
	road.push_back(0);
	road.push_back(l);
	while (n--)
	{
		int idx;
		cin >> idx;
		road.push_back(idx);
	}
	sort(road.begin(), road.end());
	int start = 1;
	int end = l;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (func(mid))
			start = mid + 1;
		else
		{
			ret = mid;
			end = mid - 1;
		}
	}
	cout << ret;
}
