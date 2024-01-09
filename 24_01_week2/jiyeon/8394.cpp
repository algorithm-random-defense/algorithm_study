/**
 * @file 8394.cpp
 * @author jiyeon
 * @brief 악수
 * @date 2024-01-09
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int fibo[n + 2];
    fibo[0] = 1, fibo[1] = 1;
    for (int i = 2; i <= n; i++)
        fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 10;

    cout << fibo[n] << endl;

    return 0;
}
/*
1 : 1
2 : 1
3 : 3
4 : 5
5 : 8
*/