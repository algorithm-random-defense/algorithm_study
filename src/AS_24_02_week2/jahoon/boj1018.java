package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 체스판 다시 칠하기
public class boj1018 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		String[] board = new String[n];
		for (int i = 0; i < n; i++) {
			board[i] = br.readLine();
		}
		int answer = n * m;
		for (int i = 0; i <= n - 8; i++) {
			for (int j = 0; j <= m - 8; j++) {
				int cnt = 0;
				for (int x = i; x < i + 8; x++) {
					for (int y = j; y < j + 8; y++) {
						if (((x + y) % 2 == (i + j) % 2 && board[i].charAt(j) != board[x].charAt(y)) ||
							((x + y) % 2 != (i + j) % 2 && board[i].charAt(j) == board[x].charAt(y))) {
							cnt++;
						}
					}
				}
				answer = Integer.min(answer, Integer.min(cnt, 64 - cnt));
			}
		}
		System.out.println(answer);
	}
}
