#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입력
    int n, len;
    int max_len = 0;      // 최장 LIS 길이
    int max_idx = -1;     // LIS의 마지막 위치
    int a[1001], dp[1001];
    vector<int> arr;
    cin >> n;

    // 연산
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                len = max(dp[j], len);
            }
        }
        dp[i] = len + 1;

        if(max_len < dp[i]) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    // 끝에서부터 추적하며 부분 수열 저장
    for(int i = max_idx; i >= 0; i--) {
        if(max_len == dp[i]) {
            arr.push_back(a[i]);
            max_len--;
        }
    }

    // 출력
    int size = arr.size();
    cout << size << "\n";

    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}