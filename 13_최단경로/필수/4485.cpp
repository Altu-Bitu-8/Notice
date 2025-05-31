#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 거리 배열 초기화를 위한 매직넘버
const int INF = 987654321;

vector<bool> visited;

typedef pair<int, int> pi;

// 다익스트라를 구현해 도착지까지의 최소비용을 리턴하는 함수
// n : 그래프의 가로 세로 길이, graph : 그래프 배열
int dijkstra(int n, const vector<vector<int>>& graph) {
    // 거리 배열 초기화 : nxn의 2차원 형태를 1차원으로 구현.
    vector<int> dist(n*n, INF);
    priority_queue<pi> pq;
    // 이동 배열
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    dist[0] = graph[0][0];
    pq.push({0, 0});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        visited[cur] = true;
        // 1차원 좌표값을 2차원으로 변환.
        int x = cur / n, y = cur % n;
        for (int i = 0; i < 4; i++) {
            // 새로운 좌표 설정
            int nx = x + dx[i], ny = y + dy[i], next = nx * n + ny;
            // 범위 확인 및 방문했는지 확인, 조건에 맞지 않을 시 contiue.
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[next]) {
                continue;
            }
            // 가능할 시 거리 갱신
            if (dist[next] > dist[cur] + graph[nx][ny]) {
                dist[next] = dist[cur] + graph[nx][ny];
                // -로 push하여 작은 값이 위로 오도록 설정. (ex: 7과 9가 있을 시 기존 : 9, 7 / 음수로 변환 시 : -7, -9 순서로 정렬됨.)
                pq.push({-dist[next], next});
            }
        }
    }
    return dist[n*n-1];
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    vector<vector<int>> graph;

    int cnt = 1;

    // 입력 : n을 입력받은 뒤 n이 0이 아닌지 확인
    while (cin >> n && n) {
        //입력받은 n에 맞춰 벡터 초기화
        graph.assign(n,vector<int>(n, 0));
        visited.assign(n*n, false);

        //그래프 입력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        
        int ans = dijkstra(n, graph);
        // 출력
        cout << "Problem " + to_string(cnt++) +": " + to_string(ans) << '\n';
    }
}