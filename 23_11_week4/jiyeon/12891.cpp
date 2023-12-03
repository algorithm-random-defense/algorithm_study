/**
 * @file 12891.cpp
 * @author jiyeon
 * @brief DNA 비밀번호
 * @date 2023-11-24
 * 
 */

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int dna_size, password_size, answer = 0, idx = 0;
    string dna;
    map<char, int> m;

    cin >> dna_size >> password_size >> dna;
    cin >> m['A'] >> m['C'] >> m['G'] >> m['T'];

    for (idx; idx < password_size - 1; idx++)
        m[dna[idx]]--;
    for (idx; idx < dna_size; idx++) {
        m[dna[idx]]--;
        if (m['A'] <= 0 && m['C'] <= 0 && m['G'] <= 0 && m['T'] <= 0)
            answer++;
        m[dna[idx - password_size + 1]]++;
    }
    cout << answer << endl;

    return 0;
}