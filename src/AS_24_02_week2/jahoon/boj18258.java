package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 큐 2
public class boj18258 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		Queue<Integer> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			int answer;
			if (cmd.equals("push")) {
				q.add(Integer.parseInt(st.nextToken()));
				continue;
			} else if (cmd.equals("pop")) {
				answer = q.isEmpty() ? -1 : q.poll();
			} else if (cmd.equals("size")) {
				answer = q.size();
			} else if (cmd.equals("empty")) {
				answer = q.isEmpty() ? 1 : 0;
			} else if (cmd.equals("front")) {
				answer = q.isEmpty() ? -1 : q.peek();
			} else {// back
				answer = q.isEmpty() ? -1 : ((LinkedList<Integer>) q).peekLast();
			}
			sb.append(answer).append("\n");
		}
		System.out.print(sb);
	}
}
