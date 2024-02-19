package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 문자열 집합
public class boj14425 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		HashMap<String, Boolean> hm = new HashMap<>();
		for (int i = 0; i < n; i++) {
			hm.put(br.readLine(), true);
		}
		int answer = 0;
		for (int i = 0; i < m; i++) {
			answer += hm.get(br.readLine()) != null ? 1 : 0;
		}
		System.out.println(answer);
	}
}
