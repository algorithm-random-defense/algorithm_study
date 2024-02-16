package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// N 과 M (1)
public class boj15649 {
	static StringBuilder sb = new StringBuilder();
	static int n, m;
	static void dfs(int cnt, StringBuilder res, boolean[] vis) {
		if (cnt >= m) {
			sb.append(res).append("\n");
			return ;
		}
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				vis[i] = true;
				int idx = res.length();
				res.append(i + 1).append(" ");
				dfs(cnt + 1, res, vis);
				res.delete(idx, res.length());
				vis[i] = false;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		boolean[] vis = new boolean[n];
		Arrays.fill(vis, false);
		dfs(0, new StringBuilder(), vis);
		System.out.println(sb);
	}
}
