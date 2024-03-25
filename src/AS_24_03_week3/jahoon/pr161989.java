package AS_24_03_week3.jahoon;

// 덧칠하기
public class pr161989 {
	class Solution {
		public int solution(int n, int m, int[] section) {
			int answer = 0, target = section[0];
			for (int idx : section) {
				if (idx >= target) {
					answer++;
					target = idx + m;
				}
			}
			return answer;
		}
	}
}
