// 주사위 쌓기

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// (1, 6), (2, 5), (3, 4) 한 쌍임

vector<vector<int> > board;
int n, res = -1, cur_res = 0;


void f() {

}

int main () {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	board = vector(n, vector(7, 0));

	for (int i = 0; i < n; i++){
		for (int j = 1; j <= 6; j++) {
			cin >> board[i][j];
		}
	}

	int badak, chunjang;
	for (int i = 0; i <= 6; i++) {
		badak = i;
		chunjang = 7 - i;
		
	}
}
