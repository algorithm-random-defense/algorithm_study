package AS_24_02_week3.jahoon;

import java.util.*;
import java.io.*;
// 파이프 옮기기 1
public class boj17070 {
	static int n, answer, nx, ny;
	static int[][] board;
	static void move(int curStatus) {
		if (curStatus != 2) {
			if (nx >= n || ny >= n || board[nx][ny] == 1) return ;
			dfs(curStatus, nx, ny);
		} else {
			if (nx >= n || ny >= n || board[nx][ny] == 1 ||
				board[nx - 1][ny] == 1 || board[nx][ny - 1] == 1) return;
			dfs(curStatus, nx, ny);
		}
	}
	static void dfs(int curStatus, int x, int y) {
		if (x == n - 1 && y == n - 1) {
			answer++;
			return;
		}
		if (curStatus == 0) {// 가로
			nx = x; ny = y + 1;
			move(0);
			nx = x + 1; ny = y + 1;
			move(2);
		} else if (curStatus == 1) {// 세로
			nx = x + 1; ny = y;
			move(1);
			nx = x + 1; ny = y + 1;
			move(2);
		} else {// 대각
			nx = x; ny = y + 1;
			move(0);
			nx = x + 1; ny = y;
			move(1);
			nx = x + 1; ny = y + 1;
			move(2);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		board = new int[n][n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0, 0, 1);
		System.out.println(answer);
	}
}
