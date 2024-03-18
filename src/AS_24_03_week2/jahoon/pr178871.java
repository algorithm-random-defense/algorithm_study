package AS_24_03_week2.jahoon;

import java.io.*;
import java.util.*;
// 달리기 경주
public class pr178871 {
	class Solution {
		public String[] solution(String[] players, String[] callings) {
			Map<String, Integer> m = new HashMap<>();
			for (int i = 0; i < players.length; i++) {
				m.put(players[i], i);
			}
			int idx;
			for (String call : callings) {
				idx = m.get(call);
				players[idx] = players[idx - 1];
				players[idx - 1] = call;
				m.put(call, idx - 1);
				m.put(players[idx], idx);
			}
			return players;
		}
	}
}
