package AS_24_03_week4.jahoon;

import java.io.*;
import java.util.*;
// 행운의 문자열
public class boj1342 {
	static int answer = 0;
	static String input;
	static Map<Character, Integer> m = new HashMap<>();
	static StringBuffer sb = new StringBuffer();

	public static void dfs(char prev) {
		if (sb.length() == input.length()) {
			answer++;
		}
		for (Map.Entry<Character, Integer> entry : m.entrySet()) {
			char c = entry.getKey();
			int cnt = entry.getValue();
			if (cnt > 0 && c != prev) {
				sb.append(c);
				m.put(c, cnt - 1);
				dfs(c);
				sb.delete(sb.length() - 1, sb.length());
				m.put(c, cnt);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		input = br.readLine();
		for (int i = 0; i < input.length(); i++) {
			m.put(input.charAt(i), m.getOrDefault(input.charAt(i), 0) + 1);
		}
		dfs('\0');
		System.out.println(answer);
  	}
}
