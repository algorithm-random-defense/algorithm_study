package AS_24_03_week1.jahoon;

import java.util.*;
import java.io.*;
//[PCCP 기출문제] 2번 / 석유 시추
public class pr50136 {
	class Solution {
		public int solution(int[][] land) {
			int answer = 0, idx = 1, cnt;
			int n = land.length, m = land[0].length;
			int vis[][] = new int[n][m];
			int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
			Deque<Integer[]> dq = new ArrayDeque<>();
			Map<Integer, Integer> cnts = new HashMap<>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (vis[i][j] == 0 && land[i][j] == 1) {
						cnt = 0;
						dq.addFirst(new Integer[]{i, j});
						vis[i][j] = idx;
						cnt++;
						while (dq.size() != 0) {
							Integer[] cur = dq.pollFirst();
							for (int dir = 0; dir <4; dir++) {
								int nx = cur[0] + dx[dir];
								int ny = cur[1] + dy[dir];
								if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
								if (vis[nx][ny] != 0 || land[nx][ny] != 1) continue;
								dq.addFirst(new Integer[]{nx, ny});
								vis[nx][ny] = idx;
								cnt++;
							}
						}
						cnts.put(idx++, cnt);
					}
				}
			}
			boolean[] checked = new boolean[idx];
			for (int j = 0; j < m; j++) {
				Arrays.fill(checked, false);
				cnt = 0;
				for (int i = 0; i < n; i++) {
					if (vis[i][j] != 0 && !checked[vis[i][j]]) {
						checked[vis[i][j]] = true;
						cnt += cnts.get(vis[i][j]);
					}
				}
				answer = Math.max(answer, cnt);
			}
			return answer;
		}
	}
}
