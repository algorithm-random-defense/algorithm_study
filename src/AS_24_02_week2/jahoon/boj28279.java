package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 덱 2
public class boj28279 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		String cmd, answer;
		Deque<String> dq = new ArrayDeque<>();
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			cmd = st.nextToken();
			if (cmd.equals("1")) {
				dq.addFirst(st.nextToken());
				continue;
			} else if (cmd.equals("2")) {
				dq.addLast(st.nextToken());
				continue;
			} else if (cmd.equals("3")) {
				answer = dq.isEmpty() ? "-1" : dq.pollFirst();
			} else if (cmd.equals("4")) {
				answer = dq.isEmpty() ? "-1" : dq.pollLast();
			} else if (cmd.equals("5")) {
				answer = String.valueOf(dq.size());
			} else if (cmd.equals("6")) {
				answer = dq.isEmpty() ? "1" : "0";
			} else if (cmd.equals("7")) {
				answer = dq.isEmpty() ? "-1" : dq.peekFirst();
			} else {
				answer = dq.isEmpty() ? "-1" : dq.peekLast();
			}
			sb.append(answer).append("\n");
		}
		System.out.print(sb);
	}
}
