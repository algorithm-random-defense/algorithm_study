package AS_24_02_week4.jahoon;

import java.io.*;
import java.util.*;
// 배열 돌리기 1
public class boj16926 {

	static int n, m, r;
	static List<Integer> list;
	static int[][] board;
	static void getSetRec(int x, int y, boolean flag) {
		int idx = 0;
		for (int j = y; j < m - y; j++) {
			if (flag) list.add(board[x][j]);
			else board[x][j] = list.get(idx++);
		}
		for (int i = x + 1; i < n - x; i++) {
			if (flag) list.add(board[i][m - y - 1]);
			else board[i][m - y - 1] = list.get(idx++);
		}
		for (int j = m - y - 2; j >= y; j--) {
			if (flag) list.add(board[n - x - 1][j]);
			else board[n - x - 1][j] = list.get(idx++);
		}
		for (int i = n - x - 2; i > x; i--) {
			if (flag) list.add(board[i][y]);
			else board[i][y] = list.get(idx++);
		}
	}

	static void rotate() {
		int idx = r % list.size();
		List<Integer> rotated = new ArrayList<>(list.size());
		rotated.addAll(list.subList(idx, list.size()));
		rotated.addAll(list.subList(0, idx));
		list = rotated;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		board = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			if (n - i * 2 <= 0 || m - i * 2 <= 0) break;
			list = new ArrayList<>(2 * (n + m - i * 4) - 4);
			getSetRec(i, i, true);
			rotate();
			getSetRec(i, i, false);
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sb.append(board[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}
