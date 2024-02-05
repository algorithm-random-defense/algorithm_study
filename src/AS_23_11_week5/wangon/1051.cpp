// 문제
// N×M크기의 직사각형이 있다.각 칸에는 한 자리 숫자가 적혀 있다.이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오.
// 이때, 정사각형은 행 또는 열에 평행해야 한다.

// 입력
//		첫째 줄에 N과 M이 주어진다.N과 M은 50보다 작거나 같은 자연수이다.둘째 줄부터 N개의 줄에 수가 주어진다.

// 출력
//		첫째 줄에 정답 정사각형의 크기를 출력한다.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[51][51];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	}
	int size = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < min(n, m); k++)
			{
				if (i + k < n && j + k < m)
				{
					if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k])
						size = max(size, (k + 1) * (k + 1));
				}
			}
		}
	}
	std::cout << size << std::endl;
}
