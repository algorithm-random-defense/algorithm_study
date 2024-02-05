#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int ret;
	for (ret = 0;; ret++)
	{
		int cnt = 0;
		int bottles = n;
		while (bottles)
		{
			if (bottles % 2)
				cnt++;
			bottles /= 2;
		}
		if (cnt <= k)
			break;
		n++;
	}
	cout << ret << endl;
}

// 이진수에서 1의 개수를 줄이는 것과 같음.
// n이 2의 제곱수라면 1개로 합칠수있음
// n % 2 = 1이라면 안합쳐지는 cnt 늘림
// 추가구매하는 물병 수인 ret 늘려가면서 계속 ㄱㄱ
