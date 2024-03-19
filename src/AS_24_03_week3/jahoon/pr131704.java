package AS_24_03_week3.jahoon;
import java.io.*;
import java.util.*;
// 택배상자
public class pr131704 {
	class Solution {
		public int solution(int[] order) {
			int cur = 0;

			Deque<Integer> dq = new ArrayDeque<>();

			for (int i = 1; i <= order.length; i++) {
				if (i  == order[cur]) {
					cur++;
					while (dq.size() > 0 && dq.peekFirst() == order[cur]) {
						cur++;
						dq.pollFirst();
					}
				} else {
					dq.addFirst(i);
				}
			}
			return cur;
		}
	}
}
