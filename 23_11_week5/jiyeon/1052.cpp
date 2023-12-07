/**
 * @file 1052.cpp
 * @author jiyeon
 * @brief 물병
 * @date 2023-12-02
 * 
 */

#include <iostream>
using namespace std;

/*
    13 2 
    물병 0개 안 샀을 때
    {2, 2, 2, 2, 2, 2, 1} // 1: 외톨이 물병 ++
    {4, 4, 4, 1} // 4: 외톨이 물병 ++
    {8, 4, 1} // 8: 외톨이 물병 ++
*/
int main() {
    int n, k;
    cin >> n >> k;

    int answer = 0;
    while (true) {
        int temp = n + answer, cnt = 0;

        while (temp > 0) { // 2로 계속 나눠주기
            if (temp % 2)
                cnt++; // 못 합쳐지고 남는 물병
            temp /= 2;
        }

        if (cnt <= k)
            break;

        answer++;
    }
    cout << answer << endl;

    return 0;
}