/**
 * @file 1025.cpp
 * @author jiyeon
 * @brief 제곱수 찾기
 * @date 2023-11-30
 * 
 */

#include <cmath>
#include <iostream>
using namespace std;

char table[10][10];
int n, m, answer = -1;

bool isSquareNum(int num) {
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

void findNum(int x, int y, int dx, int dy) {
    string num = "";
    if (dx == 0 && dy == 0) return;
    while (0 <= x && x < n && 0 <= y && y < m) {
        num += table[x][y];
        if (isSquareNum(stoi(num))) // 만들 수 있는 모든 수에 대해 제곱수인지 검사
            answer = max(answer, stoi(num));
        x += dx;
        y += dy;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> table[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // 모든 수
            for (int dx = -n; dx < n; dx++) {
                for (int dy = -m; dy < m; dy++) // 등차
                findNum(i, j, dx, dy);
            }
        }
    }
    cout << answer << endl;

    return 0;
}