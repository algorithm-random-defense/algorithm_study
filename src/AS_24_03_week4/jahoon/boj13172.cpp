#include <iostream>
using namespace std;
// Σ
#define MOD 1000000007

long long power(long long n, long long m){
    long long ret = 1;
    while(m){
        if(m & 1) ret = ret * n % MOD;
        m = m / 2;
        n = n * n % MOD;
    }
    return ret;
}

int main() {
	long long m, n, s, q, answer = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> n >> s;
		answer += (s * power(n, MOD - 2)) % MOD;
	}
	cout << answer % MOD << "\n";
}