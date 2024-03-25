package AS_24_03_week3.jahoon;
import java.io.*;
import java.util.*;
// 괄호 변환
public class pr60058 {
	class Solution {
		Deque<Character> dq = new ArrayDeque<>();

		String flip(String p, int s, int e) {
			if (s >= e) return "";
			StringBuilder sb = new StringBuilder();
			for (; s < e; s++) {
				if (p.charAt(s) == '(') sb.append(')');
				else sb.append('(');
			}
			return sb.toString();
		}

		boolean check(String p, int s, int e) {
			dq.clear();
			for (; s < e; s++) {
				char c = p.charAt(s);
				if (c == '(') {
					dq.addLast(c);
				} else if (dq.size() == 0 || dq.pollLast() != '('){
					return false;
				}
			}
			return true;
		}

		String func(String p, int idx) {
			if (idx >= p.length()) return "";
			int s = idx, cnt = 0;
			do {
				cnt = p.charAt(idx++) == '(' ? cnt + 1 : cnt - 1;
			} while (cnt != 0 && idx < p.length());
			StringBuilder sb = new StringBuilder();
			if (check(p, s, idx)) {
				return sb.append(p.substring(s, idx)).append(func(p, idx)).toString();
			}
			sb.append('(').append(func(p, idx)).append(')').append(flip(p, s + 1, idx - 1));
			return sb.toString();
		}

		public String solution(String p) {
			return func(p, 0);
		}
	}
}
