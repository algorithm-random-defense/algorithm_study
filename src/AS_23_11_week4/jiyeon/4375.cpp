/**
 * @file 4375.cpp
 * @author jiyeon
 * @brief 1
 * @date 2023-11-23
 * 
 */

#include <iostream>
using namespace std;

void solution(int input) {
    int digit = 1; // 자릿수
    unsigned long long num = 1; // 1, 11, 111, ...

    while (true) {
        if (num % input == 0)
            break;
        num = num * 10 + 1;
        num %= input; // ❗️ 시간 초과 : x mod N = (x mod N) mod N
        digit++;
    }

    cout << digit << endl;
}

int main() {
    string input;
    while (getline(cin, input))
        solution(stoi(input));

    return 0;
}