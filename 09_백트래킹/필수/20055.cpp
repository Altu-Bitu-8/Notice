#include <iostream>
#include <deque>

using namespace std;

struct info { // 각 칸마다 내구도와 로봇 존재 여부 저장
    int power;
    bool is_on = false;
};

// 벨트를 한 칸 회전
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back()); // 벨트의 마지막 칸을 앞에 push
    belt.pop_back();              // 마지막 칸을 pop
    belt[n - 1].is_on = false;    // 로봇 내리기
}

// 로봇을 움직일 수 있다면 한 칸 이동
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0~n-1인데 다음 칸과 비교하기 위해 0~n-2까지 반복
        // 현재 칸에 로봇이 존재하고, 다음 칸에 로봇이 없으며, 다음 칸에 내구도가 남아있을 때 이동 가능
        if (belt[i].is_on && !belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            belt[i].is_on = false;
            belt[i + 1].is_on = true;
            belt[i + 1].power--;
        }
    }
    belt[n - 1].is_on = false; // 로봇 내리기
}

// 올리는 칸에 로봇을 올릴 수 있다면 올리기
void putRobot(deque<info> &belt) {
    // 올리는 칸의 내구도가 남아 있으면
    if (belt[0].power >= 1) {
        belt[0].is_on = true;
        belt[0].power--;
    }
}

// 벨트의 내구도 체크
bool checkFinish(deque<info> &belt, int n, int k) {
    int cnt = 0; // 내구도 0인 칸의 개수
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            cnt++;
        }
    }

    return cnt >= k;
}

int solution(deque<info> &belt, int n, int k) {
    // 1단계부터 시작
    int step = 1;
    while (true) {
        // 1. 벨트 회전
        rotateBelt(belt, n);

        // 2. 로봇 이동
        moveRobot(belt, n);

        // 3. 로봇 올리기
        putRobot(belt);

        // 4. 내구도가 0인 칸의 개수가 k개 이상인지 체크
        if (checkFinish(belt, n, k)) {
            return step;
        }
        step++;
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동
 *    (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 회전을 구현하기 위해, 양 끝에서 삽입과 삭제가 가능한 deque을 이용하여 풀이
 *
 * 1번 벨트 회전: 벨트의 마지막 원소를 벨트의 처음으로 이동
 * 2번 로봇 이동: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사
 *               -> 로봇을 옮길 수 있으면 존재 여부 체크하고 내구도 감소
 * 3번 로봇 추가: 올리는 위치 칸의 내구도가 0이 아니라면 해당 칸의 로봇 존재 여부 체크 + 내구도 감소
 *
 * >> 주의: 칸 번호를 1번이 아닌 0번부터 시작하는 것으로 관리하고 있기 때문에, n번 칸이 아니라 n-1번 칸이 내리는 위치 <<
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, k; // 컨베이어 벨트의 길이, 내구도 0인 칸의 최대 개수
    cin >> n >> k;
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장

    // 벡트의 각 칸마다 내구도 입력, 로봇 존재 여부 초기화
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> belt[i].power;
    }

    // 연산 & 출력
    cout << solution(belt, n, k);
}