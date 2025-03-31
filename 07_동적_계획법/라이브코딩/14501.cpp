#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

void dpBottomUp(vector<int>& dp, vector<ii> li, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + li[i].first; j <= n; j++) {
            if (dp[j] < dp[i] + li[i].second) { // 만약에 기존 값보다 크다면 새로 dp[j] 값 갱신
                dp[j] = dp[i] + li[i].second;
            }
        }
    }
}

void dpTopDown(vector<int>& dp, vector<ii> li, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (i + li[i].first > n) { // 상담이 퇴사일을 넘기면
            dp[i] = dp[i + 1]; // 상담하지 않고 이전 값 유지
        }
        else { // 상담을 하는 것과 하지 않는 것 중 큰 값을 선택
            dp[i] = max(dp[i + 1], li[i].second + dp[i + li[i].first]);
        }
    }
}

int main() {
    int n;
    int a, b;
    cin >> n;

    vector<ii> li; // 상담 기간과 금액
    vector<int> dp(n + 1, 0); // i번째 날의 최대 금액

    // 입력
    for (int i = 0; i<n;i++) {
        cin >> a >> b;
        li.push_back(make_pair(a,b));
    }


    // dpTopDown(dp, li, n);
    // cout << dp[0] << "\n";

    dpBottomUp(dp, li, n);
    cout << dp[n] << "\n";

    return 0;
}