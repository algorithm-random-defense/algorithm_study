/**
 * @file 1072.cpp
 * @author jiyeon
 * @brief 게임
 * @date 2024-01-27
 * 
 */

#include <iostream>
using namespace std;

/*
100 * (y + n) / (x + n) = z + 1
(100y + 100n) / (x + n) = z + 1
100y + 100n = (x + n) * (z + 1)
100y + 100n = xz + x + zn + n
(99 - z)n = xz + x - 100y
n = (xz + x - 100y) / (99 - z)
*/
int main() {
    long long x, y;
    cin >> x >> y;

    long long z = y * 100 / x;
    if (z >= 99) {
        cout << "-1" << endl;
        return 0;
    }

    long long n = x * z + x - 100 * y;
    long long m = 99 - z;
    if (n % m) cout << n / m + 1 << endl;
    else cout << n / m << endl;

    return 0;
}
