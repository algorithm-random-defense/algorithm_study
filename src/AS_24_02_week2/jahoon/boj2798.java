package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 블랙잭
public class boj2798 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()),  m = Integer.parseInt(st.nextToken());
		ArrayList<Integer> arr = new ArrayList<>(n);
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		int answer = 0, sum;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					sum = arr.get(i) + arr.get(j) + arr.get(k);
					if (sum > m) continue;
					answer = Integer.max(answer, sum);
				}
			}
		}
		System.out.println(answer);
	}
}
