#include <iostream>
using namespace std;
// 사과나무
int n, now, cnt, sum;

int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> now ;
        sum += now ;
        cnt += now / 2 ;
    }
    if (sum % 3 != 0) {
		cout << "NO\n" ;
	} else {
		cout << (cnt >= sum / 3 ? "YES\n" : "NO\n");
	}
}