/**
 * @file 1013.cpp
 * @author jiyeon
 * @brief Contact
 * @date 2023-11-27
 * 
 */

#include <iostream>
using namespace std;

// (100+1+ | 01)+ : 100+1+ 또는 01이 올 수 있음 -> 무조건 1로 끝남
bool isFollowPattern(string input) {
    for (int idx = input.size() - 1; idx >= 0; idx--) {
        if (input[idx] == '0') {
            return false;
        }
        if ((idx == 1 && input[idx - 1] == '0') || idx > 1 && input[idx - 1] == '0' && input[idx - 2] != '0') { // 01
            idx--;
        } else { // 100+1+
            int one_cnt = 0;
            while (idx >= 0 && input[idx] == '1') { // 1+
                one_cnt++;
                idx--;
            }
            if (one_cnt < 1)
                return false;
            int zero_cnt = 0;
            while (idx >= 0 && input[idx] == '0') { // 0+
                zero_cnt++;
                idx--;
            }
            if (zero_cnt < 2 || idx < 0 || input[idx] != '1')
                return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        if (isFollowPattern(input))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}