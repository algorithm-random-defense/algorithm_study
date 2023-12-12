#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int arr[51];
	arr[0] = 1;
	arr[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= 50; i++)
		arr[i] = (arr[i - 2] + arr[i - 1] + 1);
	cout << int(arr[n] % 1000000007) << endl;
}
