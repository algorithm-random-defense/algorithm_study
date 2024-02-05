/**
 * @file 2580.cpp
 * @author jiyeon
 * @brief 스도쿠
 * @date 2023-12-15
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> blank;

bool check(int x, int y, int value) { // 겹치는 값이 있는지 CHEK
    // 가로, 세로
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == value) return false;
        if (board[i][y] == value) return false;
    }
    // 3x3 정사각형
    int xx = (x / 3) * 3, yy = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[xx + i][yy + j] == value) return false;
        }
    }
    return true;
}

bool sudoku(int n) {
    if (n == blank.size()) return true;
    // n번째 빈칸 채울 차례
    int x = blank[n].first;
    int y = blank[n].second;
    for (int value = 1; value <= 9; value++) {
        if (check(x, y, value)) { // 1~9까지 시도
            board[x][y] = value;
            if (sudoku(n + 1)) // 다음 칸 채우러 ...
                return true;
        }
    }
    board[x][y] = 0; // 조건이 안 맞아 못 채웠으면 다시 0으로
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0)
                blank.push_back({i, j});
        }
    }

    sudoku(0);

    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    return 0;
}