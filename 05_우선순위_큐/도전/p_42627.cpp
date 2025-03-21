#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
 * HINT: 현재 시각에서 요청된 task 중 소요시간이 가장 적은 task를 우선으로 실행해야 해요!
 * 시간이 흘러감에 따라 수행돼야 하는 기능을 생각해보세요!
 */

struct jobInfo {
    int idx;           // 작업 인덱스
    int request_time;  // 작업 요청 시간
    int duration;      // 작업 소요 시간
};

struct cmp {
    bool operator()(const jobInfo &child, const jobInfo &parent) {
        // 1. duration이 짧은게 우선
        if (parent.duration != child.duration) {
            return parent.duration < child.duration;
        }
        // 2. idx가 적은게 우선
        return parent.idx < child.idx;
    }
};

/*
 * [디스크 컨트롤러]
 * - 차근차근 구현하면 되는 문제.
 *
 * - 처음부터 우선순위 큐에 넣을 수 없음
 * - 현재 시간이 요청 시간 이후인 경우, 우선순위 큐에 삽입
 * - 우선순위에 따라 꺼내면서 작업 진행
 */

int solution(vector<vector<int>> jobs) {
    int sum = 0, curr_time = 0, idx = 0;

    // 작업 시간대로 정렬
    sort(jobs.begin(), jobs.end());
    // 현재 작업을 시작할 수 있는 일들의 우선순위큐
    priority_queue<jobInfo, vector<jobInfo>, cmp> pq;

    while (true) {
        // 현재 작업 가능한 큐가 비어있고,아직 남은 작업 중 가장 빠른 요청 시간이 안된 경우
        if (pq.empty() && jobs[idx][0] > curr_time) {
            curr_time = jobs[idx][0];  // 시간 넘기기
        }

        // 현재 작업할 수 있는 일들 꺼내서 우선순위 큐에 넣기
        while (idx < jobs.size() && jobs[idx][0] <= curr_time) {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }

        curr_time += pq.top().duration;            // 작업이 완료된 후 현재 시간
        sum += curr_time - pq.top().request_time;  // 전체 걸린 시간 더하기
        pq.pop();

        // 작업을 전부 꺼냈고, 우선순위 큐도 비어있으면 모든 작업 종료
        if (idx >= jobs.size() && pq.empty()) {
            break;
        }
    }

    // 평균시간 리턴
    return sum / jobs.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<vector<int>> jobs(n, vector<int>(2));  // jobs[i]: { 작업 i가 요청되는 시점, 작업 i의 소요시간 }

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i][0] >> jobs[i][1];
    }

    // 연산 & 출력
    cout << solution(jobs);

    return 0;
}