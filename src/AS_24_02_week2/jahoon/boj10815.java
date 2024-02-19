package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 숫자 카드
public class boj10815 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		HashMap<String, Boolean> hm = new HashMap<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			hm.put(st.nextToken(), true);
		}
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			bw.append(String.valueOf((hm.get(st.nextToken()) != null ? 1 : 0))).append(" ");
		}
		bw.flush();
	}
}
