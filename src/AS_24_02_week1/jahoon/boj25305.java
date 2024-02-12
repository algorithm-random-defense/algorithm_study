package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;

public class boj25305 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		ArrayList<Integer> arr = new ArrayList<>(n);
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		arr.sort(Collections.reverseOrder());
		System.out.println(arr.get(k - 1));
	}
}
