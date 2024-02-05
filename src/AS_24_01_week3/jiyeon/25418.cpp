/**
 * @file 25418.cpp
 * @author jiyeon
 * @brief 정수 a를 k로 만들기
 * @date 2024-01-18
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int a, k;
    cin >> a >> k;

    queue<int> q;
    int visited[1000002] = {0, };

    q.push(a);

    while (!q.empty()) {
        int num = q.front(); q.pop();
        int x = num + 1, y = num * 2;

        if (x <= k && visited[x] == 0) {
            q.push(x);
            visited[x] = visited[num] + 1;
        }
        if (y <= k && visited[y] == 0) {
            q.push(y);
            visited[y] = visited[num] + 1;
        }
    }

    cout << visited[k] << endl;

    return 0;
}