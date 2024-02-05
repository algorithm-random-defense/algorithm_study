#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// DNA 비밀번호

int main() {
	unordered_map<char,int> um;
	int s, p, answer=0;
	cin >> s >> p;
	string input;
	cin >> input;
	cin >> um['A'] >> um['C'] >> um['G'] >> um['T'];

	for (int i=0; i<p-1; i++) {
		um[input[i]]--;
	}
	for (int i=p-1; i<s; i++) {
		um[input[i]]--;
		if (um['A'] <= 0 && um['C'] <= 0 && um['G'] <= 0 && um['T'] <= 0) {
			answer++;
		}
		um[input[i-p+1]]++;
	}
	cout << answer;
}