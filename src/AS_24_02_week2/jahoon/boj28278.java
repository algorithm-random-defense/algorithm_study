package AS_24_02_week2.jahoon;

import java.io.*;
import java.util.*;
// 스택 2
public class boj28278 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		int cmd;
		int answer;
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			cmd = Integer.parseInt(st.nextToken());

			if (cmd == 1) {
				stack.push(Integer.parseInt(st.nextToken()));
				continue;
			} else if (cmd == 2) {
				answer = stack.empty() ? -1 : stack.pop();
			} else if (cmd == 3) {
				answer = stack.size();
			} else if (cmd == 4) {
				answer = stack.empty() ? 1 : 0;
			} else {
				answer = stack.empty() ? -1 : stack.peek();
			}
			sb.append(answer).append("\n");
		}
		System.out.print(sb);
	}
}
