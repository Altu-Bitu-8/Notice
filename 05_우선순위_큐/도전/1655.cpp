#include <iostream>
#include <queue>

using namespace std;

/*
 * [HINT]
 * 매번 정렬하지 않기 위해서는 입력된 숫자 중 상위 숫자와 하위 숫자를 분리하여 저장하는 것이 좋겠네요!
 */

/*
 * [가운데를 말해요]
 * 입력된 N개의 숫자 중 크기 순으로 가운데에 위치한 숫자를 찾는 문제
 * 입력되는 순간마다 가운데를 말해야 하므로 매번 정렬하면 시간초과!
 *
 * => 상위 숫자와 하위 숫자를 구분하여 저장해야 함.
 * 상위 숫자의 경우, 경계에 위치한 숫자는 상위 숫자 중 최솟값 -> 최소 힙
 * 하위 숫자의 경우, 경계에 위치한 숫자는 하위 숫자 중 최댓값 -> 최대 힙
 *
 * - 기본적으로 하위 숫자의 최댓값이 '가운데'가 된다.
 * - 새로운 숫자가 입력되면, 우선 현재 '가운데'를 기준으로 상위 숫자인지, 하위 숫자인지 구분하여 힙에 삽입
 * - 상위 숫자와 하위 숫자의 크기는 같거나, 하위 숫자가 1개 더 많아야 함.
 * */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int> lower_numbers;                          // 하위 숫자 저장
    priority_queue<int, vector<int>, greater<>> upper_numbers;  // 상위 숫자 저장

    while (n--) {
        cin >> x;

        // 상위 숫자 중 최솟값보다 더 큰 값이 들어온 경우
        if (!upper_numbers.empty() && x > upper_numbers.top()) {
            upper_numbers.push(x);  // 상위 숫자에 추가
        } else {
            lower_numbers.push(x);  // 하위 숫자에 추가
        }

        // 하위 숫자와 상위 숫자는 개수가 같거나, 하위 숫자가 1크도록 유지되어야 함.
        if (lower_numbers.size() < upper_numbers.size()) {  // 상위 숫자가 더 많다면 하위 숫자로 옮기기
            lower_numbers.push(upper_numbers.top());
            upper_numbers.pop();
        } else if (lower_numbers.size() > upper_numbers.size() + 1) {  // 하위 숫자가 상위 숫지 +1 보다 더 많은 경우
            upper_numbers.push(lower_numbers.top());
            lower_numbers.pop();
        }

        cout << lower_numbers.top() << '\n';
    }

    return 0;
}