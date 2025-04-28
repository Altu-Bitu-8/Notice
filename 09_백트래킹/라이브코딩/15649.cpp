#include <iostream>
#include <vector>

using namespace std;

/*
 * idx: 현재 결정해야 하는 수열의 인덱스
 * */
void backtrakcing(int n, int m, int idx, vector<int> &sequence, vector<bool> &is_used) {
    if (idx == m) {  // m개를 다 골랐을 경우 출력 후 종료
        for (auto x : sequence) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    // n개 중 다음 숫자를 뽑아야 함
    for (int i = 1; i <= n; i++) {
        if (is_used[i]) {  // 이미 사용한 숫자인 경우 패스
            continue;
        }

        // 사용
        is_used[i] = true;
        sequence[idx] = i;

        // 다음 인덱스 진행
        backtrakcing(n, m, idx + 1, sequence, is_used);

        // 반납
        is_used[i] = false;
    }
}

int main() {
    // 입력
    int n, m;
    cin >> n >> m;

    vector<int> sequence(m, -1);         // 현재 수열 저장
    vector<bool> is_used(n + 1, false);  // 방문 여부 저장

    // 연산 + 출력
    backtrakcing(n, m, 0, sequence, is_used);
}