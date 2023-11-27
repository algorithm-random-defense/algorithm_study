#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

int cnt = 0;
//찾으려고 돌리는 횟수. 어차피 한번 도니까 static으로 둔다

void R(int target, std::deque<int> &q) //앞 원소를 뒤로 돌리는 함수
{
	while (target != q.front())
	{
		q.push_back(q.front());
		q.pop_front();
		cnt++;
	}
}

void RR(int target, std::deque<int> &q) //뒤 원소를 앞으로 돌리는 함수
{
	while (target != q.front())
	{
		q.push_front(q.back());
		q.pop_back();
		cnt++;
	}
}

int main()
{
	//1. n,m, deque 초기화
	int n, m;
	std::cin >> n >> m;
	std::deque<int> q;
	for (int i = 1; i <= n; i++)
		q.push_back(i);
	//2. m 횟수만큼 반복문 돌면서 target 넘버 찾기
	for (int i = 0; i < m; i++)
	{
		int target;
		std::cin >> target;
		while (1)
		{
			//3. 현재 들어있는 인덱스가 덱 사이즈 절반보다 작으면 앞에서 돌림, 크면 뒤에서 돌림
			int idx = std::find(q.begin(), q.end(), target) - q.begin();
			if (idx < q.size() - idx)
				R(target, q);
			else
				RR(target, q);
			//4. 찾았으면 Pop
			q.pop_front();
			break;
		}
	}
	//5. 출력!
	std::cout << cnt << std::endl;
	return 0;
}
