#include <iostream>
#include <vector>

using namespace std;

int backtracking(int i, int n, vector<bool> &check_cols, vector<bool> &check_left, vector<bool> &check_right) {
    if (i == n) {  // 모든 퀸을 다 놓은 경우 경우의 수 하나 추가
        return 1;
    }

    int ans = 0;

    for (int j = 0; j < n; j++) {
        // 퀸을 놓을 수 있는지 확인
        if (check_cols[j] || check_left[i + j] || check_right[i - j + n - 1]) {
            continue;
        }

        // 사용
        check_cols[j] = true;
        check_left[i + j] = true;
        check_right[i - j + n - 1] = true;

        // 가능한 경우의 수 탐색
        ans += backtracking(i + 1, n, check_cols, check_left, check_right);

        // 반납
        check_cols[j] = false;
        check_left[i + j] = false;
        check_right[i - j + n - 1] = false;
    }

    return ans;
}

int main() {
    // 입력
    int n;
    cin >> n;
    vector<bool> check_cols(n, false);           // 열 체크
    vector<bool> check_left(2 * n - 1, false);   // 좌하향 대각선 체크
    vector<bool> check_right(2 * n - 1, false);  // 우하향 대각선 체크

    // 연산 & 출력
    cout << backtracking(0, n, check_cols, check_left, check_right);
}