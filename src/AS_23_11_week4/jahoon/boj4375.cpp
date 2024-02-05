#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 1
/*
	n % x = (n % x) % x 임을 이용하자
*/
int main() {
    int n;
    while(cin >> n){
		int answer=1, k=1;
		while(answer % n){
			k++;
			answer = answer*10 + 1;
			answer %= n;
		}
		cout << k << "\n";
	}
	return 0;
}
