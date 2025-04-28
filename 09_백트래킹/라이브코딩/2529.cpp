#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DIGIT_SIZE = 10;
string answer[2] = {"0000000000", "9999999999"};  // MAX, MIN

void updateAnswer(vector<int> &sequence) {
    string tmp = "";
    for (int i = 1; i < sequence.size(); i++) {
        tmp += to_string(sequence[i]);
    }

    // 정답 업데이트
    answer[0] = max(answer[0], tmp);
    answer[1] = min(answer[1], tmp);
}

void backtracking(int idx, int k, vector<int> &sequence, vector<bool> &is_used, vector<bool> &is_ascending) {
    if (idx > k + 1) {
        updateAnswer(sequence);
        return;
    }

    int next_num = sequence[idx - 1];  // 직전 수에서 출발

    while (true) {
        // 부등호에 따라 증가 혹은 감소
        if (is_ascending[idx - 1]) {
            next_num++;
        } else {
            next_num--;
        }

        // 숫자가 범위 내에 있는지 확인
        if (next_num < 0 || next_num >= DIGIT_SIZE) {
            break;
        }

        // 이미 사용한 수면 넘어가기
        if (is_used[next_num]) {
            continue;
        }

        // 사용
        is_used[next_num] = true;
        sequence[idx] = next_num;

        // 연산
        backtracking(idx + 1, k, sequence, is_used, is_ascending);

        // 반납
        is_used[next_num] = false;
    }
}

int main() {
    // 입력
    int k;
    cin >> k;
    vector<bool> is_used(DIGIT_SIZE, false);
    vector<bool> is_ascending(k + 1);
    vector<int> sequence(k + 2, -1);

    char x;
    for (int i = 1; i <= k; i++) {
        cin >> x;
        is_ascending[i] = x == '<';
    }

    is_ascending[0] = true;
    sequence[0] = -1;
    backtracking(1, k, sequence, is_used, is_ascending);

    for (int i = 0; i < 2; i++) {
        cout << answer[i] << '\n';
    }
}