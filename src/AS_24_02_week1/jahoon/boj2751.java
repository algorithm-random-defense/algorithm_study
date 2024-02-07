package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;
public class boj2751 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		ArrayList<Integer> arr = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(br.readLine()));
		}
		Collections.sort(arr);
		arr.forEach(a->sb.append(a).append('\n'));
		System.out.print(sb);
	}
}
