package AS_24_02_week4.jahoon;

import java.io.*;
import java.util.*;
// 30
public class boj10610 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n = br.readLine();

		int sum = 0;
		for(int i = 0; i < n.length(); i ++) {
			sum += n.charAt(i) - '0';
		}
		if (!n.contains("0") || sum % 3 != 0) {
			System.out.println("-1");
			return;
		}
		char[] array = n.toCharArray();
		Arrays.sort(array);
		StringBuilder sb = new StringBuilder();
		for(int i = array.length - 1; i >= 0; i--) {
			sb.append(array[i]);
		}
		System.out.println(sb);
	}
}
