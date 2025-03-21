#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [HINT]
 * 모든 수를 저장하기에는 메모리가 부족해요.
 * 입력을 받으면서 저장할 필요가 있는지 판단이 필요해요.
 */

/**
 * [N번째 큰 수]
 *
 * - 메모리 제한이 있으므로, 입력값을 모두 저장하면 안됨
 * - 입력을 받으면서, 저장할 필요가 없어진 값을 삭제해야 함
 * - 상위 n개만 저장하면서, 새로운 값을 포함해 해당 시점에서 가장 작은 값을 삭제해야 함
 * => 최소힙을 사용!
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> pq;  // 최소 힙

    for (int i = 0; i < n * n; i++) {
        cin >> x;

        pq.push(x);

        if (pq.size() > n) {  // 힙의 크기가 n 이상이면 가장 작은 값 삭제
            pq.pop();
        }
    }

    // 출력
    cout << pq.top();
}