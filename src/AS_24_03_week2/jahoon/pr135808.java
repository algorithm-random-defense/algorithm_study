package AS_24_03_week2.jahoon;

import java.io.*;
import java.util.*;
// 과일 장수
public class pr135808 {


	class Solution {
		public int solution(int k, int m, int[] score) {
			int answer = 0, idx = score.length % m;
			Arrays.sort(score);
			for (; idx < score.length; idx += m) {
				answer += score[idx] * m;
			}
			return answer;
		}
	}
}
