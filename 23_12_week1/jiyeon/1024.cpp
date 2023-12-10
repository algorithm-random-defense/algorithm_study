/**
 * @file 1024.cpp
 * @author jiyeon
 * @brief 수열의 합
 * @date 2023-12-06
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    while (l <= 100) {
        int sum = 0, start = n / l;
        for (int i = 0; i < l; i++)
            sum += start + i;
        
        if (abs(sum - n) % l == 0) { // 수열 찾았다 !
            start -= abs(sum - n) / l;
            if (start >= 0) {
                for (int i = 0; i < l; i++)
                    cout << start + i << " ";
                cout << endl;
                return 0;
            }
        }
        l++;
    }
    cout << -1 << endl;

    return 0;
}

// 18 2
// 18 / 2 = 9 -> 9 + 10 = 19 -> 8 + 9 = 17 -> l++
// 18 / 3 = 6 -> 6 + 7 + 8 = 21 -> 5 + 6 + 7 = 18 -> !!!

// 18 4
// 18 / 4 = 4 -> 4 + 5 + 6 + 7 = 22 -> 3 + 4 + 5 + 6 = 18 -> !!!
// n / l ~ n / l + l 만큼 더한 값을 sum이라고 하면,
// abs(n - abs) % l == 0이면 .......... ! 답이 있는 거야 
