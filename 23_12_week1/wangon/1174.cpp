// 음이 아닌 정수를 십진법으로 표기했을 때, 왼쪽에서부터 자리수가 감소할 때, 그 수를 줄어드는 수라고 한다.예를 들어, 321와 950은 줄어드는 수이고, 322와 958은 아니다.

// N번째로 작은 줄어드는 수를 출력하는 프로그램을 작성하시오.만약 그러한 수가 없을 때는 -1을 출력한다.가장 작은 줄어드는 수가 1번째 작은 줄어드는 수이다.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> arr;
	queue<long long> index;

	for (int i = 0; i <= 9; i++)
	{
		arr.push_back(i);
		index.push(i);
	}
	while (index.size() != 0)
	{
		long long idxN = index.front();
		index.pop();
		for (int i = 0; i < idxN % 10; i++)
		{
			long long descN = 10 * idxN + i;
			arr.push_back(descN);
			index.push(descN);
		}
	}
	if (n > arr.size())
		cout << "-1" << endl;
	else
		cout << arr[n - 1] << endl;
}


//큐 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 21, 31, 32 ...]
//돌면서 큐[n] % 10 보다 작은 수를 큐[n] * 10 하면서 더해준다면 채울수 있다 !
// 0 1 2 3 4 5 6 7 8 9

// 0보다 작은 수 없음
// 10 - 1보다 작은 수
// 20 21 -2보다 작은 수
// 30 31 32
// 40 41 42 43
// 50 51 52 53 54
// 60 61 62 63 64 65
// 70 71 72 73 74 75 76
// 80 81 82 83 84 85 86 87
// 90 91 92 93 94 95 96 97 98

//  - 0보다 작은수 없음
// 20 - 0보다 작은수 없음


// 2 10

// 3 10 20 21
// 4 10 20 21 30 31 32

// 9 87

// 3
// 2 10
// 4 3 10 20 21
//   2 10
