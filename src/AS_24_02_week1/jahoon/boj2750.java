package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;

public class boj2750 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		List<Integer> arr = new ArrayList<>(100);
		for (int i = 0; i < n; i++) {
			arr.add(i, Integer.parseInt(br.readLine()));
		}
		Collections.sort(arr);
		arr.forEach(System.out::println);
	}
}
