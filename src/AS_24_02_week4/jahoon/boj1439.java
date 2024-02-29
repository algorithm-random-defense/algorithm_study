package AS_24_02_week4.jahoon;

import java.io.*;
import java.util.*;
public class boj1439 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int zero = 0, one = 0;
		for (int i = 0; i < s.length();) {
			char c = s.charAt(i);
			if (c == '1') one++;
			else zero++;
			while (i < s.length() && s.charAt(i) == c) {
				i++;
			}
		}
		System.out.println(Math.min(zero, one));
	}
}
