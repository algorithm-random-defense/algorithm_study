/**
 * @file 11497.cpp
 * @author jiyeon
 * @brief 통나무 건너뛰기
 * @date 2023-12-14
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 2 4 5 7 9 -> 2 5 9 7 4
void solution(int size, vector<int> tree) {
    sort(tree.begin(), tree.end());

    vector<int> arr;
    for (int i = 0; i < size; i += 2)
        arr.push_back(tree[i]);
    for (int i = size - 1 - size % 2; i >= 0; i -= 2)
        arr.push_back(tree[i]);
    
    int answer = 0;
    for (int i = 1; i < size; i++)
        answer = max(answer, abs(arr[i] - arr[i - 1]));

    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> tree(n, 0);
        for (int j = 0; j < n; j++)
            cin >> tree[j];
        solution(n, tree);
    }

    return 0;
}
