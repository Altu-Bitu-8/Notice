/**
 * [HINT]: 이 문제에서 필요한 체크 배열은 무엇일까요? 문제에 주어진 조건을 살펴보아요.
 */

#include <iostream>
#include <vector>

using namespace std;

// 연산자 정의
const int OPERATOR_SIZE = 4;
enum OPERATOR {
    ADD,
    SUB,
    MUL,
    DIV,
};

int answer[2] = {-1000000000, 1000000000};  // MAX, MIN

/*
 * 연산자에 따른 계산
 */
int calculate_value(int op, int value1, int value2) {
    switch (op) {
        case ADD:
            return value1 + value2;
        case SUB:
            return value1 - value2;
        case MUL:
            return value1 * value2;
        case DIV:
            return value1 / value2;
    }
}

/*
 * 연산자를 하나씩, 총 n-1개가 될 때까지 뽑는다.
 * i: 현재 연산자 순서 (1 ~ n-1)
 * n: 뽑아야 할 연산자 개수
 * value: 현재 계산된 값
 * numbers: 피연산자 배열
 * operators: 연산자 개수 배열
 */
void backtracking(int i, int n, int value, vector<int> &numbers, vector<int> &operators) {
    if (i == n) {
        answer[0] = max(answer[0], value);
        answer[1] = min(answer[1], value);
        return;
    }

    // op: 연산자 번호
    for (int op = 0; op < OPERATOR_SIZE; op++) {
        if (operators[op] == 0) {
            continue;
        }
        // 연산자 사용
        operators[op]--;
        int new_value = calculate_value(op, value, numbers[i]);
        backtracking(i + 1, n, new_value, numbers, operators);

        // 반납
        operators[op]++;
    }
}

int main() {
    // 입력
    int n;
    cin >> n;

    vector<int> numbers(n);
    vector<int> operators(OPERATOR_SIZE);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < OPERATOR_SIZE; i++) {
        cin >> operators[i];
    }

    // 연산
    backtracking(1, n, numbers[0], numbers, operators);

    // 출력
    cout << answer[0] << '\n'
         << answer[1] << '\n';

    return 0;
}