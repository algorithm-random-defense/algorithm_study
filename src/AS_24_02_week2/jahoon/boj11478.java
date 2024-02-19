package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 서로 다른 부분 문자의 개수
public class boj11478 {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int size = (s.length() * (s.length() + 1) / 2);
		HashSet<String> hs = new HashSet<>(size);
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j <= s.length(); j++) {
				hs.add(s.substring(i, j));
			}
		}
		System.out.println(hs.size());
	}
}
