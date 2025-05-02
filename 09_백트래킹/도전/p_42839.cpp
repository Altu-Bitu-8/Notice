/**
 * [HINT]: 모든 조각을 다 사용해야 할 필요가 없어요! 현재 숫자 길이에 상관 없이 답의 후보가 될 수 있습니다.
 */
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int x) {
    if (x <= 1) {  // 1 이하는 소수 아님
        return false;
    }

    // 소수 체크 배열
    vector<bool> primes(sqrt(x) + 1, true);

    for (int i = 2; i * i <= x; i++) {
        if (!primes[i]) {  // 소수가 아닌 경우
            continue;
        }

        if (x % i == 0) {  // 소수로 나누어지면 소수가 아님
            return false;
        }
        for (int j = i * 2; j * j <= x; j += i) {  // 소수의 배수 체크
            primes[j] = false;
        }
    }

    // x 이하의 수로 나눠질 수 없는 경우 -> 소수
    return true;
}

int backtracking(int number, vector<int> &check) {
    int answer = isPrime(number);  // 현재 숫자가 소수인 경우 답이 될 수 있음

    // 현재 숫자가 0인 경우, 1부터 선택 가능
    int start_num = number == 0 ? 1 : 0;

    for (int i = start_num; i < 10; i++) {
        if (check[i] > 0) {                                  // 숫자가 남아 있으면
            check[i]--;                                      // 개수를 줄이고
            answer += backtracking(number * 10 + i, check);  // 탐색
            check[i]++;                                      // 반납
        }
    }
    return answer;
}

/**
 * [소수 찾기]
 * - 주어진 숫자를 이어서 만들 수 있는 수 중 소수의 개수를 찾는 문제
 * - 만드는 숫자 길이에 제한이 없기 때문에, 모든 단계에서 수를 확인해주어야 한다.
 * - 같은 숫자가 적혀있는 종이 조각을 구분하지 않아도 된다.
 * - 중복 제거
 *      - 1(a)1(b) vs 1(b)1(a): 처음부터 둘을 구분하지 않고 같은 1이 두개 있는 것으로 간주함
 *      - 011과 11의 구분: 현재 숫자가 0일 때는 0을 선택할 수 없도록 함
 */
int solution(string numbers) {
    int answer = 0;

    // 각 숫자가 몇개 남았는지 체크하는 벡터
    vector<int> check(10, 0);

    // 등장한 숫자 개수 세기
    for (char c : numbers) {
        check[c - '0']++;
    }

    return backtracking(0, check);
}

int main() {
    string numbers;
    cin >> numbers;

    cout << solution(numbers);
}