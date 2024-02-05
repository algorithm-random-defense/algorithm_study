/**
 * @file 1051.cpp
 * @author jiyeon
 * @brief 숫자 정사각형
 * @date 2023-12-01
 * 
 */

#include <cmath>
#include <iostream>
using namespace std;

char rectangle[51][51];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> rectangle[i][j];

    int answer = 1;
    for (int i = 1; i < min(n, m); i++) {
        for (int x = 0; x < n - i; x++) {
            for (int y = 0; y < m - i; y++) {
                int a = rectangle[x][y];
                int b = rectangle[x + i][y];
                int c = rectangle[x][y + i];
                int d = rectangle[x + i][y + i];
                if (a == b && b == c && c == d)
                    answer = pow(i + 1, 2);
            }
        }
    }
    cout << answer << endl;

    return 0;
}