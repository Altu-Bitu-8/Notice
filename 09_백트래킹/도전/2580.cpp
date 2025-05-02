/*
 * [HINT]: 행, 열, 칸(3*3) 모두 고려해야 해요. 특정 행, 열, 칸에 특정 숫자가 존재하는지 반복문을 쓰지 않고 한번에 확인할 수 있는 방법은 없을까요?
 */

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

typedef vector<vector<int>> board_i;
typedef vector<vector<bool>> board_b;

int getAreaNum(int r, int c) {
    return (r / 3) * 3 + c / 3;
}

/**
 * cnt: 현재 칸 수 (총 81칸)
 * return: 현재 상황에서 스도쿠가 완성 될 수 있는지 여부.
 */
bool backtracking(int cnt, board_i &sudoku, board_b &check_rows, board_b &check_cols, board_b &check_areas) {
    if (cnt == SIZE * SIZE) {  // 마지막 칸까지 다 간 경우
        return true;
    }

    int r = cnt / SIZE;  // 현재 행
    int c = cnt % SIZE;  // 현재 열

    // 이미 채워져 있는 경우 다음 칸으로
    if (sudoku[r][c] != 0) {
        return backtracking(cnt + 1, sudoku, check_rows, check_cols, check_areas);
    }

    // 1~9까지 돌아가면서
    for (int x = 1; x <= SIZE; x++) {
        int areaNum = getAreaNum(r, c);

        // 채울 수 없다면 넘어가기
        if (check_rows[r][x] || check_cols[c][x] || check_areas[areaNum][x]) {
            continue;
        }

        // 사용
        check_rows[r][x] = true;
        check_cols[c][x] = true;
        check_areas[areaNum][x] = true;
        sudoku[r][c] = x;

        // 이대로 진행하다가 스도쿠가 완성되면 그대로 종료해도 됨
        if (backtracking(cnt + 1, sudoku, check_rows, check_cols, check_areas)) {
            return true;
        }

        // 반납
        check_rows[r][x] = false;
        check_cols[c][x] = false;
        check_areas[areaNum][x] = false;
        sudoku[r][c] = 0;
    }

    // 현재 칸에서 모든 경우에 대해 실패함
    return false;
}

/**
 * [스도쿠]
 * 빈 칸에 1~9를 작성하여 완전한 스도쿠 판을 출력한다.
 * 단, 답이 여러 개인 경우 한 가지만 출력하면 된다.
 */

int main() {
    board_i sudoku(SIZE, vector<int>(SIZE));                   // 스도쿠 판
    board_b check_rows(SIZE, vector<bool>(SIZE + 1, false));   // check_rows[r][n]: r번 행에 n이 존재하는지 여부
    board_b check_cols(SIZE, vector<bool>(SIZE + 1, false));   // check_cols[c][n]: c번 열에 n이 존재하는지 여부
    board_b check_areas(SIZE, vector<bool>(SIZE + 1, false));  // check_areas[s][n]: s번 정사각형에 n이 존재하는지 여부

    // 입력
    int tmp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> tmp;

            // 사용 표기
            check_rows[i][tmp] = true;
            check_cols[j][tmp] = true;
            check_areas[getAreaNum(i, j)][tmp] = true;
            sudoku[i][j] = tmp;
        }
    }

    // 연산
    backtracking(0, sudoku, check_rows, check_cols, check_areas);

    // 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}