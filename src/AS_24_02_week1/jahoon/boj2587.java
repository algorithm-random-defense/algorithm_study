package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;
public class boj2587 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<>();
		int num = 0;
		for (int i = 0; i < 5 ; i++) {
			arr.add(Integer.parseInt(sc.next()));
			num += arr.get(i);
		}
		Collections.sort(arr);
		System.out.println(num / 5);
		System.out.println(arr.get(2));
	}
}
