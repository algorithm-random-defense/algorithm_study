package AS_24_03_week2.jahoon;

import java.io.*;
import java.util.*;
// [PCCE 기출문제] 10번 / 데이터 분석
public class pr250121 {
	class Solution {
		public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
			Map<String, Integer> m = new HashMap<>(Map.of("code", 0, "date", 1, "maximum", 2, "remain", 3));
			List<int[]> list = new ArrayList<>(data.length);
			for (int[] d : data) {
				int extIdx = m.get(ext);
				if (d[extIdx] > val_ext) continue;
				list.add(d);
			}
			int sortIdx = m.get(sort_by);
			Collections.sort(list, (a, b) -> {return a[sortIdx] - b[sortIdx];});
			int[][] answer = new int[list.size()][4];
			for (int i = 0; i < list.size(); i++) {
				answer[i] = list.get(i);
			}
			return answer;
		}
	}
}
