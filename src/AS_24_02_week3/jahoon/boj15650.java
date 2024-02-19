package AS_24_02_week3.jahoon;

import java.util.*;
import java.io.*;
// N과 M (2)
public class boj15650 {
	static int n, m;
	static StringBuilder sb = new StringBuilder();
	static int[] arr;
	static void dfs(int idx, int cnt) {
		if (cnt == m) {
			for (int num : arr) {
				sb.append(num).append(" ");
			}
			sb.append("\n");
			return ;
		}

		for (int i = idx; i <= n; i++) {
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[m];
		dfs(1, 0);
		System.out.print(sb);
	}
}
