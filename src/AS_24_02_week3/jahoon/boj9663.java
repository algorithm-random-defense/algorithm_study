package AS_24_02_week3.jahoon;

import java.io.*;
// N-Queen
public class boj9663 {
	static int n;
	static int answer = 0;
	static int[] board;

	static boolean isValid(int cnt, int idx) {
		for (int i = 0; i < cnt; i++) {
			if (board[i] == idx || Math.abs(cnt - i) == Math.abs(board[i] - idx)) {
				return false;
			}
		}
		return true;
	}

	static void dfs(int cnt) {
		if (cnt == n) {
			answer++;
			return ;
		}
		for (int i = 0; i < n; i++) {
			if (isValid(cnt, i)) {
				board[cnt] = i;
				dfs(cnt + 1);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		board = new int[n];
		dfs(0);
		System.out.println(answer);
	}
}
