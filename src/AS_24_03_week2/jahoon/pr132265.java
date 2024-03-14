package AS_24_03_week2.jahoon;

import java.io.*;
import java.util.*;
// 롤케이트 자르기
public class pr132265 {
	class Solution {
		public int solution(int[] topping) {
			int answer = 0, lcnt = 0, rcnt = 0, target;
			Map<Integer, Integer> l = new HashMap<>();
			Map<Integer, Integer> r = new HashMap<>();

			for (int t : topping) {
				r.put(t, r.getOrDefault(t, 0) + 1);
			}
			rcnt = r.size();
			for (int t : topping) {
				l.put(t, l.getOrDefault(t, 0) + 1);
				lcnt = l.size();
				target = r.get(t) - 1;
				if (target == 0) rcnt--;
				r.put(t, target);
				if (lcnt != rcnt) continue;
				answer++;
			}

			return answer;
		}
	}
}
