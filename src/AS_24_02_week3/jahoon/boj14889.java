package AS_24_02_week3.jahoon;

import java.util.*;
import java.io.*;
// 스타트와 링크
public class boj14889 {
	static int n;
	static int answer = Integer.MAX_VALUE;
	static int[][] board;
	static boolean[] vis;

	static void getScore() {
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i] == vis[j]) {
					total += (vis[i] ? 1 : -1) * board[i][j];
				}
			}
		}
		answer = Math.min(answer, Math.abs(total));
	}

	static void dfs(int cnt, int idx) {
		if (cnt == n / 2) {
			getScore();
			return ;
		}
		for (int i = idx; i < n; i++) {
			if (!vis[i]) {
				vis[i] = true;
				dfs(cnt + 1, i + 1);
				vis[i] = false;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		board = new int[n][n];
		vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0, 0);
		System.out.println(answer);
	}
}
