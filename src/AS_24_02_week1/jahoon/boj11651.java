package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;

public class boj11651 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[][] arr = new int[n][2];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr, (a, b)-> {
			if (a[1] == b[1]) {
				return a[0] - b[0];
			}
			return a[1] - b[1];
		});
		for (int i = 0; i < n; i++) {
			bw.append(String.valueOf(arr[i][0])).append(" ")
				.append(String.valueOf(arr[i][1])).append("\n");
		}
		bw.flush();
	}
}
