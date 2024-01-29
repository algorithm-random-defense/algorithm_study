#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int t;

int isInside(int cX, int cY, int rad, int x, int y)
{
	return (pow(x - cX, 2) + pow(y - cY, 2) <= pow(rad, 2));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		int cnt = 0;
		int startX, startY, endX, endY, n;
		cin >> startX >> startY >> endX >> endY;
		cin >> n;
		while (n--)
		{
			int circleX, circleY, rad;
			cin >> circleX >> circleY >> rad;
			if (isInside(circleX, circleY, rad, startX, startY) != isInside(circleX, circleY, rad, endX, endY))
				cnt++;
		}
		cout << cnt << endl;
	}
}
