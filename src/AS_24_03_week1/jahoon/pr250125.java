package AS_24_03_week1.jahoon;

//[PCCE 기출문제] 9번 / 이웃한 칸
public class pr250125 {
	class Solution {
		public int solution(String[][] board, int h, int w) {
			int answer = 0;
			int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
			for (int dir = 0; dir < 4; dir++) {
				int nx = h + dx[dir];
				int ny = w + dy[dir];
				if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) continue;
				if (board[nx][ny].equals(board[h][w])) answer++;
			}
			return answer;
		}
	}
}
