#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int TREE_ONE = 1; // 1번 나무
const int TREE_TWO = 2; // 2번 나무

// 자두를 잡을 수 있는지 판단하는 함수
// 움직인 횟수가 짝수이면 1번 나무, 홀수이면 2번 나무 아래에 있다고 간주
bool canCatchPlum(int move_cnt, int position) {
    return (position == TREE_ONE && move_cnt % 2 == 0) ||
           (position == TREE_TWO && move_cnt % 2 == 1);
}

// 최대 자두 개수를 구하는 함수
int getMaxPlum(int t, int w, vector<int> &plum) {
    // dp[i][j]: i초에 j번 움직였을 때 잡을 수 있는 자두의 최대 개수
    vector<vector<int> > dp(t + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= t; i++) {
        // 한 번도 움직이지 않은 경우 분리 (인덱스 에러 방지)
        dp[i][0] = dp[i - 1][0];

        // 자두가 1번 나무에서 떨어질 경우 개수 + 1
        if (plum[i] == TREE_ONE) {
            dp[i][0] += 1;
        }

        for (int j = 1; j <= w; j++) {
            // 이전에 같은 위치에 있었던 경우와 이전보다 한 번 더 움직인 경우 비교
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);

            // 자두를 잡을 수 있는 경우 개수 + 1
            if (canCatchPlum(j, plum[i])) {
                dp[i][j] += 1;
            }
        }
    }

    // 마지막 시간 t의 가능한 모든 이동 횟수 중에서 최대 자두 개수 반환
    return *max_element(dp[t].begin(), dp[t].end());
}

int main() {
    // 입력
    int t, w;
    cin >> t >> w;

    vector<int> plum(t + 1); // 1초부터 시작하므로 인덱스 1부터 사용
    for (int i = 1; i <= t; ++i) {
        cin >> plum[i];
    }

    // 연산 & 출력
    cout << getMaxPlum(t, w, plum);

    return 0;
}
