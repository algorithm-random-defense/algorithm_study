#include <iostream>
#include <vector>
using namespace std;
// 틱택토
vector<string> board(3);
int xCnt, oCnt;

bool checkWinner() {
	int xWins=0, oWins=0;
	if (!(xCnt == oCnt || xCnt - oCnt == 1)) return false;// 순서대로 안둔 상황
	for (int i=0; i<3; i++) {
		if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			board[i][0] == 'X' ? xWins++ : oWins++;
		}
		if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			board[0][i] == 'X' ? xWins++ : oWins++;
		}
	}
	if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		board[0][0] == 'X' ? xWins++ : oWins++;
	}
	if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		board[0][2] == 'X' ? xWins++ : oWins++;
	}
	if (!xWins && !oWins && xCnt+oCnt != 9) return false;// 다 안뒀는데 게임도 안끝난 상황
	if (xCnt == oCnt && xWins) return false;// O가 두기전부터 게임이 끝난 상황
	if (xCnt - oCnt == 1 && oWins) return false;// X가 두기전부터 게임이 끝난 상황
	return true;
}

int main() {
	string s;
	while (cin >> s && s != "end") {
		xCnt=0; oCnt=0;
		for (int i=0; i<9; i++) {
			if (s[i] == 'X') {
				xCnt++;
			} else if(s[i] == 'O') {
				oCnt++;
			}
		}
		for (int i=0; i<3; i++) {
			board[i] = s.substr(i*3, 3);
		}
		cout << (checkWinner() ? "valid\n" : "invalid\n");
	}
}