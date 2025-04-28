
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 15;

bool promising(int num, vector<int>& column_indices) {
    int idx = 0;
    while (idx < num) {  // 이미 놓여있는 모든 퀸에 대해
        // abs(column_indices[num] - column_indices[idx]) : 두 퀸의 행 차이
        // num - idx : 두 퀸의 열 차이 (idx < num이므로  항상 양수)
        // 따라서 두 퀸의 행 차이와 열 차이가 같으면 두 퀸을 잇는 선의 기울기의 절댓값이 1이 되므로, 같은 대각선에 위치한다는 뜻
        if (column_indices[num] == column_indices[idx] || abs(column_indices[num] - column_indices[idx]) == (num - idx)) {  // 같은 행, 같은 대각선 체크
            return false;
        }
        idx++;
    }
    return true;
}

int backtracking(int cnt, int n, vector<int>& column_indices) {
    if (cnt == n) {  // 모든 퀸을 다 놓은 경우 경우의 수 하나 추가
        return 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        column_indices[cnt] = i;  // i행 cnt열에 퀸 배치

        // 퀸을 놓을 수 있다면
        if (promising(cnt, column_indices)) {
            ans += backtracking(cnt + 1, n, column_indices);
        }
    }

    return ans;
}

/**
 * [백트래킹 풀이]
 *
 * 가지치기 시 유망성 검사하는 부분의 시간복잡도 O(n)
 *
 * 시간 약 4360ms
 *
 * 해설 : https://myunji.tistory.com/201
 */

int main() {
    int n;
    // 입력
    cin >> n;

    vector<int> column_indices(n, -1);  // column_indices[i]: i행에 퀸이 몇 열에 놓였는지

    // 연산 + 출력
    cout << backtracking(0, n, column_indices);

    return 0;
}