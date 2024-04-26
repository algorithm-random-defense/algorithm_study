#include <iostream>
#include <cstring>
// 1학년
using namespace std;
long long n, num[101], d[101][101];

long long dp(int i, int j) {
    if (i > n - 2 || j < 0 || j > 20) return 0;
    if (i == n - 2 && j == num[n - 1]) return 1;
    if (d[i][j] == -1) {
    	d[i][j] = dp(i + 1, j + num[i + 1]) + dp(i + 1, j - num[i + 1]);
	}
    return d[i][j];
}

int main(){
    memset(d, -1, sizeof(d));
    cin >> n;
    for(int i = 0; i < n; i++) {
		cin >> num[i];
	}
    cout << dp(0, num[0]);
}