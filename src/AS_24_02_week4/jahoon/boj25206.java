package AS_24_02_week4.jahoon;

import java.io.*;
import java.util.*;
// 너의 평점은
public class boj25206 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Map<String, Double> m = Map.of("A+", 4.5, "A0", 4.0, "B+", 3.5, "B0", 3.0,
			"C+", 2.5, "C0", 2.0, "D+", 1.5, "D0", 1.0, "F", 0.0, "P", 0.0);
		double answer = 0.0;
		double total = 0.0;
		while (true) {
			String s = br.readLine();
			if (s == null) {
				break;
			}
			StringTokenizer st = new StringTokenizer(s); st.nextToken();
			double grade = Double.parseDouble(st.nextToken());
			String rating = st.nextToken();
			if (rating.equals("P")) continue;
			total += grade;
			answer += grade * m.get(rating);
		}
		System.out.println(answer / total);
	}
}
