package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;
// 좌표 압축
public class boj18870 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		ArrayList<Integer> arr = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		HashSet<Integer> al = new HashSet<>(arr);
		ArrayList<Integer> sorted = new ArrayList<>(al);
		HashMap<Integer, Integer> hm = new HashMap<>(n);
		Collections.sort(sorted);
		for (int i = 0; i < sorted.size(); i++) {
			hm.put(sorted.get(i), i);
		}
		for (Integer num : arr) {
			sb.append(hm.get(num)).append(" ");
		}
		System.out.println(sb);
	}
}
