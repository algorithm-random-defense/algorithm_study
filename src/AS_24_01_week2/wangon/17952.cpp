// 과제는 끝나지 않아!
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct subject {
	int score;
	int deadline;
};

vector<subject> arr(1000000);
int ret = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int flag;
		cin >> flag;
		if (flag)
		{
			subject obj;
			cin >> obj.score >> obj.deadline;
			arr.push_back(obj);
		}
		arr.back().deadline--;
		if (arr.back().deadline == 0)
		{
			ret += arr.back().score;
			arr.pop_back();
		}
	}
	cout << ret;
}
