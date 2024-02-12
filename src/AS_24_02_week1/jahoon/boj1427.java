package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;
public class boj1427 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char [] arr = br.readLine().toCharArray();
		Arrays.sort(arr);
		StringBuilder sb = new StringBuilder();
		System.out.println(sb.append(arr).reverse());
	}
}
