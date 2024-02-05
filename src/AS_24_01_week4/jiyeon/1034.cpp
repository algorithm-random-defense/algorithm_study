/**
 * @file 1034.cpp
 * @author jiyeon
 * @brief 램프
 * @date 2024-01-26
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k, answer = 0;
    cin >> n >> m;
    vector<string> table(n);
    for (int i = 0; i < n; i++)
        cin >> table[i];
    cin >> k;

    for (string row : table) {
        int off_cnt = 0;
        for (char status : row)
            if (status == '0') off_cnt++;
        // 한 행에 꺼진 램프의 수가 k보다 작거나 같아야 모두 켤 수 있음
        // k가 짝수이면 꺼진 램프의 수도 짝수, 홀수이면 홀수여야 모두 켤 수 있음
        if (off_cnt > k || off_cnt % 2 != k % 2)
            continue;
        // 모두 켤 수 있는 조건의 행과 같은 조건인 행의 개수가 정답 후보
        int same_cnt = 0;
        for (string temp : table)
            if (row == temp) same_cnt++;
        answer = max(answer, same_cnt);
    }
    cout << answer << endl;

    return 0;
}