#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> board(9, vector<int>(9));

bool isAble(int x, int y, int num) {
    for (int i=x-x%3; i<x-x%3+3; i++) {
        for (int j=y-y%3; j<y-y%3+3; j++) {
            if (board[i][j] == num) return false;
        }
    }
	for(int i=0; i<9; i++) {
        if(board[x][i] == num || board[i][y] == num) return false;
    }
    return true;
}

void sudoku(int x,int y) {
    if (x==9) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
	if (y==9) {
		sudoku(x+1,0);
	} else if (board[x][y]==0) {
        for(int i=1; i<=9; i++) {
            if (isAble(x, y, i)) {
                board[x][y] = i;
                sudoku(x, y+1);
                board[x][y] = 0;
            }
        }
    }
    else {
		sudoku(x,y+1);
	}
}

int main() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
        }
    }
    sudoku(0,0);
    return 0;
}