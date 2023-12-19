/**
 * @file 2116.cpp
 * @author jiyeon
 * @brief 주사위 쌓기
 * @date 2023-12-12
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v_index = {5, 3, 4, 1, 2, 0}; // 반대편 인덱스

int findMaxValue(vector<int> dice, int& value) {
    int idx = find(dice.begin(), dice.end(), value) - dice.begin();
    value = dice[v_index[idx]]; // 다음 value 반대편 값으로 갱신
    dice.erase(dice.begin() + idx);
    dice.erase(find(dice.begin(), dice.end(), value));
    return *max_element(dice.begin(), dice.end()); // 옆 면 중에 최고
}

int main() {
    int n, answer = 0;
    // 입력 받기
    cin >> n;
    vector<vector<int>> dice(n);
    for (int i = 0; i < n; i++) {
        dice[i].resize(6, 0);
        for (int j = 0; j < 6; j++)
            cin >> dice[i][j];
    }
    // A~F까지 닿는 면 바꿔가며 가장 큰 경우 구하기
    for (int num = 1; num <= 6; num++) {
        int sum = 0, value = num; // value : 주사위끼리 닿는 면의 숫자
        for (int i = 0; i < n; i++)
            sum += findMaxValue(dice[i], value);
        answer = max(answer, sum);
    }

    cout << answer << endl;
    
    return 0;
}
