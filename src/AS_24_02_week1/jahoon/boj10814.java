package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;
// 나이순 정렬
public class boj10814 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		String[][] members = new String[n][2];

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			members[i][0] = st.nextToken();
			members[i][1] = st.nextToken();
		}
		Arrays.sort(members, Comparator.comparingInt(a -> Integer.parseInt(a[0])));
		for (String[] m : members) {
			bw.append(m[0]).append(" ").append(m[1]).append("\n");
		}
		bw.flush();
	}
}
