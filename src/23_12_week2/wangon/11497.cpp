#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ret = -1;
		vector<int> arr(n);
		deque<int> tmp;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		tmp.push_back(*(arr.end() - 1));
		arr.pop_back();
		int flag = 1;
		while (arr.size() > 0)
		{
			if (flag == 1)
				tmp.push_back(*(arr.end() - 1));
			else
				tmp.push_front(*(arr.end() - 1));
			flag *= -1;
			arr.pop_back();
		}
		for (int i = 0; i < n - 1; i++)
			ret = max(ret, abs(tmp[i] - tmp[i+1]));
		ret = max(ret, abs(tmp[n-1] - tmp[0]));
		cout << ret << endl;
	}
}
