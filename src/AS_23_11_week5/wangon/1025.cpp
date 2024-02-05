#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSquare(int n)
{
	int root = sqrt(n);
	return root * root == n;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i]; // 스트링으로 집어넣어줌

	int maxr = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int diff_i = -n; diff_i < n; diff_i++) //배열 순회용 반복문
			{
				for (int diff_j = -m; diff_j < m; diff_j++) // 배열 순회용 반복문
				{
					if (diff_i == 0 && diff_j == 0) // 이동이 없으면 등차수열 아니므로 제외
						continue;
					string nb = "";
					int cur_i = i, cur_j = j;
					while (cur_i >= 0 && cur_i < n && cur_j >= 0 && cur_j < m)
					{
						nb += arr[cur_i][cur_j]; // diff_i, diff_j 만큼 똑같이 이동하며 만들 수 있는 수 탐색, nb string에 append
						if (isSquare(stoi(nb))) // 제곱수인지 판별
							maxr = max(maxr, stoi(nb));
						cur_i += diff_i; // 이동
						cur_j += diff_j;
					}
				}
			}
		}
	}
	cout << maxr << endl;
}
