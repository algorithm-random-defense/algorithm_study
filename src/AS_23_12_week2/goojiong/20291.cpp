/**
 * @file 20291.cpp
 * @author jiyeon
 * @brief 파일 정리
 * @date 2023-12-11
 * 
 */

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    map<string, int> m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        m[input.substr(input.find('.') + 1)]++;
    }

    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}