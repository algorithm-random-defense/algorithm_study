/**
 * @file 1038.cpp
 * @author jiyeon
 * @brief 감소하는 수
 * @date 2024-01-25
 * 
 */

#include <algorithm>
#include <iostream>
using namespace std;

vector<string> decrease_num;

bool compare(const string& a, const string& b) {
    return a.length() < b.length() 
    || (a.length() == b.length() && a < b);
}

void getDecreaseNum(string num, int units) {
    num += '0' + units;
    decrease_num.push_back(num);
    for (int i = 0; i < units; i++)
        getDecreaseNum(num, i);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        getDecreaseNum("", i);

    sort(decrease_num.begin(), decrease_num.end(), compare);

    if (n >= decrease_num.size()) cout << "-1" << endl;
    else cout << decrease_num[n] << endl;

    return 0;
}
