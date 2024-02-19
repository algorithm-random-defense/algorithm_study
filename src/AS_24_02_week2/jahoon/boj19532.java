package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 수학은 비대면강의입니다
public class boj19532 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken()), f = Integer.parseInt(st.nextToken());
		int x = (c*e - b*f) / (a*e - b*d);
		int y = (c*d - a*f) / (b*d - a*e);

		System.out.println(x + " " + y);
	}
}
