#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 긴 증가 부분 수열(LIS)의 길이를 계산하는 함수
int getLISLength(int n, vector<int>& num) {
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { // 현재 인덱스 이전 요소 모두 확인
            if (num[i] > num[j]) {
                ans[i] = max(ans[i], ans[j] + 1); // 최대 수열 길이 갱신
            }
        }
    }

    return *max_element(ans.begin(), ans.end());
}

int main()
{
    // 입력
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i]; 
    }

    // 연산 & 출력
    cout << getLISLength(n, num);

    return 0;
}