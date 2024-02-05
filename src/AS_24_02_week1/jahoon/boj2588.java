package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;

public class boj2588 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(br.readLine());
		String b = br.readLine();

		System.out.println(a * Integer.parseInt(String.valueOf(b.charAt(2))));
		System.out.println(a * Integer.parseInt(String.valueOf(b.charAt(1))));
		System.out.println(a * Integer.parseInt(String.valueOf(b.charAt(0))));
		System.out.println(a * Integer.parseInt(String.valueOf(b)));
	}
}
