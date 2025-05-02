/**
 * [HINT]: 일단 방문할 수 있는 도시를 차례차례 방문해볼까요? 출발 도시로 다시 돌아왔다면 가는 길을 알게 된 거네요! 어느 곳에서 출발해도 똑같겠어요.
 */

#include <iostream>
#include <vector>

using namespace std;

int answer = 1e7;  // 최대 비용 1 000 000 * 최대 도시 수 10

void backtracking(int cnt, int n, int curr_city, int sum, vector<bool> &check, vector<vector<int>> &cost) {
    if (sum >= answer) {  // 현재 최솟값보다 커진 경우
        return;
    }

    if (cnt == n) {
        if (cost[curr_city][0] != 0) {  // 출발 도시로 다시 돌아갈 수 있는가?
            answer = min(answer, sum + cost[curr_city][0]);
        }
        return;
    }

    for (int next_city = 0; next_city < n; next_city++) {
        if (check[next_city] || cost[curr_city][next_city] == 0) {
            continue;
        }

        check[next_city] = true;
        backtracking(cnt + 1, n, next_city, sum + cost[curr_city][next_city], check, cost);
        check[next_city] = false;
    }
}

int main() {
    // 입력
    int n;
    cin >> n;

    vector<bool> check(n, false);
    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // 연산
    check[0] = true;
    backtracking(1, n, 0, 0, check, cost);

    cout << answer;
}