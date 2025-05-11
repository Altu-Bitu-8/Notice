#include <iostream>
#include <vector>

using namespace std;

/**
 * 굴다리 전체를 비추는지 확인
*/
bool check(const vector<int>& light, int n, int m, int length) {
    if (light[0] > length) {  // 첫 번째 가로등 처리
        return false;
    }

    for (int i = 1; i < m; i++) {
        if (light[i] - light[i - 1] > 2 * length) {
            return false;
        }
    }

    if (n - light[m - 1] > length) {  // 마지막 가로등 처리
        return false;
    }

    return true;
}

/**
 * 이분 탐색 함수
*/
int binarySearch(int n, int m, const vector<int>& light) {
    int start = 0;
    int end = n;
    int ans = end;  // 초기값 설정
    int mid = (start + end) / 2; 

    while (start <= end) {

        // mid가 조건에 부합한다면
        if (check(light, n, m, mid)) {
            ans = mid; // 정답 처리
            // 더 짧은 길이로 다음 탐색
            end = mid - 1;
        } else {
            // 조건에 부합하지 않는다면, 더 긴 길이로 다음 탐색
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n, m;
    cin >> n >> m;
    vector<int> light(m);
    for (int i = 0; i < m; i++){
        cin >> light[i];
    }

    // 연산
    int result = binarySearch(n, m, light);

    // 출력
    cout << result;

    return 0;
}