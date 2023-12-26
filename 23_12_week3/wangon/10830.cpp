// 행렬 제곱
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long n, b;
long long arr[5][5];
long long ret[5][5];
long long tmp[5][5];

void multiply(long long a[5][5], long long b[5][5])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++)
				tmp[i][j] += a[i][k] * b[k][j];
			tmp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = tmp[i][j];
	}
}

int main()
{
	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
		ret[i][i] = 1;
	}
	while (b > 0)
	{
		if (b % 2 == 1)
			multiply(ret, arr);
		multiply(arr, arr);
		b /= 2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
}

// A의 b제곱을 구할 때 ,하나씩 곱해 나갈 수 있지만 거듭제곱한 결과를 가져간다면 그럴 필요 X -> 연산시간 줄어듬
// A의 5제곱 -> A의 2제곱 * A의 2제곱 * A
// b를 2로 나누어가면서 쪼갤 수 있을때까지 쪼개가며 제곱한 결과를 가져가면서 연산
