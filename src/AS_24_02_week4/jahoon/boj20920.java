package AS_24_02_week4.jahoon;

import java.util.*;
import java.io.*;
// 영단어 암기는 괴로워
public class boj20920 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			if (s.length() < m) continue;
			map.put(s, map.getOrDefault(s, 0) + 1);
		}
		List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());
		list.sort((a, b) -> {
			if (a.getValue().equals(b.getValue())) {
				if (a.getKey().length() == b.getKey().length()) {
					return a.getKey().compareTo(b.getKey());
				}
				return b.getKey().length() - a.getKey().length();
			}
			return b.getValue() - a.getValue();
		});
		StringBuilder sb = new StringBuilder();
		for (Map.Entry<String, Integer> l : list) {
			sb.append(l.getKey()).append('\n');
		}
		System.out.print(sb);
	}
}
