/**
 * @file 9009.cpp
 * @author jiyeon
 * @brief 피보나치
 * @date 2023-11-21
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000001

vector<int> fibo;

void setFibonacci() { // 피보나치 수열 구하기
    fibo.push_back(0);
    fibo.push_back(1);

    int k = 2, num;
    while ((num = fibo[k - 1] + fibo[k - 2]) < MAX) {
        fibo.push_back(num);
        k++;
    }
}

void solution(int n) {
    vector<int> answer;
    for (int i = fibo.size() - 1; i > 0; i--) {
        if (fibo[i] <= n) { // 가장 가까운 작은 값
            n -= fibo[i];
            answer.push_back(fibo[i]);
        }
    }
    for (int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i] << " ";
    cout << endl;
}

int main() {
    setFibonacci();

    int t, num;
    cin >> t;
    while (t--) {
        cin >> num;
        solution(num);
    }

    return 0;
}