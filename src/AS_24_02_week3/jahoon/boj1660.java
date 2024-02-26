package AS_24_02_week3.jahoon;

import java.io.*;
import java.util.*;
// 캡틴 이다솜
public class boj1660 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		List<Integer> layer = new ArrayList<>(); layer.add(1);
		List<Integer> arr = new ArrayList<>(); arr.add(1);
		int[] dp = new int[n + 1]; dp[1] = 1;
		for (int i = 2; n > arr.get(arr.size() - 1); i++) {
			layer.add(layer.get(layer.size() - 1) + i);
			int num = arr.get(arr.size() - 1) + layer.get(layer.size() - 1);
			if (num > n) break;
			arr.add(num);
			dp[arr.get(arr.size() - 1)] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < arr.size() && arr.get(j) < i && dp[i] != 1; j++) {
				int candi = Math.min(dp[i - 1] + 1, dp[i - arr.get(j)] + 1);
				dp[i] = dp[i] == 0 ? candi : Math.min(dp[i], candi);
			}
		}
		System.out.println(dp[n]);
	}
}
