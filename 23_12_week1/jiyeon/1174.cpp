/**
 * @file 1174.cpp
 * @author jiyeon
 * @brief 줄어드는 수
 * @date 2023-12-04
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

// ("", 2) : num = 2
// ("2", 0) : num = 20, ("2", 1) : num = 21
//                      ("21", 0) : num = 210
void getDecreaseNum(string num, int units) {
    num += '0' + units; // 일의자리 더해줌 units: 일의자리라는 뜻 ㅎ
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

    if (n > decrease_num.size()) cout << "-1" << endl;
    else cout << decrease_num[n - 1] << endl;

    return 0;
}
