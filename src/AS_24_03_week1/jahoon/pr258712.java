package AS_24_03_week1.jahoon;

import java.io.*;
import java.util.*;
// 가장 많이 받은 선물
class Solution {
	public int solution(String[] friends, String[] gifts) throws Exception {
		int answer = 0;
		Map<String, Integer> grades = new HashMap<>();
		Map<String, Integer> cnts = new HashMap<>();
		for (String g : gifts) {
			StringTokenizer st = new StringTokenizer(g);
			String from = st.nextToken();
			String to = st.nextToken();
			grades.put(from, grades.getOrDefault(from, 0) - 1);
			grades.put(to, grades.getOrDefault(to, 0) + 1);
			cnts.put(from + "_" + to, cnts.getOrDefault(from + "_" + to, 0) + 1);
		}
		for (String from : friends) {
			int cnt = 0;
			for (String to : friends) {
				if (from.equals(to)) continue;
				Integer fromTo = cnts.getOrDefault(from + "_" + to, 0);
				Integer toFrom = cnts.getOrDefault(to + "_" + from, 0);
				if ((fromTo != null && fromTo > toFrom ) ||
					(fromTo == toFrom && grades.getOrDefault(from, 0) < grades.getOrDefault(to, 0))) {
					cnt++;
				}
			}
			answer = Math.max(answer, cnt);
		}
		return answer;
	}
}
