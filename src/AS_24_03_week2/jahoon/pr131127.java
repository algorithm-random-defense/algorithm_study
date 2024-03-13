package AS_24_03_week2.jahoon;

import java.io.*;
import java.util.*;
// 할인 행사
public class pr131127 {
	class Solution {
		public int solution(String[] want, int[] number, String[] discount) {
			int answer = 0;
			Map<String, Integer> m = new HashMap<>();
			for (int i = 0; i < want.length; i++) {
				m.put(want[i], number[i]);
			}
			for (int i = 0; i < 9; i++) {
				m.put(discount[i], m.getOrDefault(discount[i], 0) - 1);
			}
			for (int i = 9; i < discount.length; i++) {
				m.put(discount[i], m.getOrDefault(discount[i], 0) - 1);
				boolean able = true;
				for (String w : want) {
					if (m.get(w) > 0) {
						able = false;
						break ;
					}
				}
				if (able) answer++;
				m.put(discount[i - 9], m.get(discount[i - 9]) + 1);
			}
			return answer;
		}
	}
}
