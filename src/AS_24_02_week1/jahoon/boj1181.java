package AS_24_02_week1.jahoon;

import java.io.*;
import java.util.*;
public class boj1181 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		HashSet<String> hs = new HashSet<>(n);
		for (int i = 0; i < n; i++) {
			hs.add(br.readLine());
		}
		ArrayList<String> al = new ArrayList<>(hs);
		al.sort((a, b) -> {
			if (a.length() == b.length()) {
				return a.compareTo(b);
			}
			return a.length() - b.length();
		});
		for (String s : al) {
			bw.append(s).append("\n");
		}
		bw.flush();
	}
}
