package AS_24_03_week1.jahoon;

//
public class pr250137 {
	class Solution {
		public int solution(int[] bandage, int health, int[][] attacks) throws Exception {
			int curTime = 0;
			int curHealth = health;
			for (int[] attack : attacks) {
				int time = attack[0] - 1 - curTime;
				int heal = time >= bandage[0] ? time * bandage[1] + bandage[2] * (time / bandage[0]) : time * bandage[1];
				curHealth = Math.min(curHealth + heal, health);
				curHealth -= attack[1];
				if (curHealth <= 0) return -1;
				curTime = attack[0];
			}
			return curHealth;
		}
	}
}
