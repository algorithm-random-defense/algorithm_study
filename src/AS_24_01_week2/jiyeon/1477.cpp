/**
 * @file 1477.cpp
 * @author jiyeon
 * @brief 휴게소 세우기
 * @date 2024-01-10
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 입력 받기
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> spots; int location;
    while (cin >> location) spots.push_back(location);
    spots.push_back(0); spots.push_back(l);
    sort(spots.begin(), spots.end());

    // 고속도로의 끝에는 세울 수 없음
    int start = 1, end = l - 1, answer = end;

    while (start <= end) {
        int mid = (start + end) / 2;
        
        int cnt = 0; // mid 간격으로 휴게소를 세웠을 때 세울 수 있는 개수 🏠
        for (int i = 1; i < spots.size(); i++) {
            int dist = spots[i] - spots[i - 1];
            if (dist > mid) {
                cnt += (dist - 1) / mid;
                if (cnt > m) break;
            }
        }

        if (cnt > m) {
            start = mid + 1;
        } else {
            end = mid - 1;
            answer = min(answer, mid);
        }
    }

    cout << answer << endl;

    return 0;
}