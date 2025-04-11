//1. BFS 탐색

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edge; // 트리를 인접 리스트로 표현
int answer = 0; // 리프 노드 개수를 저장할 변수
int deleteNode; // 삭제할 노드

// BFS 탐색을 통해 리프 노드 개수를 찾는 함수
void bfs(int root) {
    if (root == deleteNode) return; // 루트 노드가 삭제 대상이면 바로 종료
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int cur = q.front(); // 큐의 맨 앞 노드를 가져옴
        q.pop(); // 큐에서 제거
        
        // 현재 노드가 리프 노드인지 확인
        if (edge[cur].empty() || (edge[cur].size() == 1 && edge[cur][0] == deleteNode)) {
            answer++; // 리프 노드 개수 증가
            continue;
        }
        
        // 현재 노드의 모든 자식 노드를 큐에 추가
        for (int next : edge[cur]) {
            if (next == deleteNode) continue; // 삭제 대상 노드는 건너뜀
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0);
    cout.tie(0);
    
    int n, root = 0;
    cin >> n; // 노드 개수 입력
    edge.resize(n); // 인접 리스트 크기 설정
    
    // 트리 입력 받기
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < 0) {
            root = i; // 루트 노드 설정
        } else {
            edge[num].push_back(i); // 부모-자식 관계 저장
        }
    }
    cin >> deleteNode; // 삭제할 노드 입력
    
    bfs(root); // BFS 탐색 실행
    
    cout << answer << "\n"; // 리프 노드 개수 출력
    return 0;
}


//2. DFS 탐색

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge; // 트리를 인접 리스트로 표현
int answer = 0; // 리프 노드 개수를 저장할 변수
int deleteNode; // 삭제할 노드

// DFS 탐색을 통해 리프 노드 개수를 찾는 함수
void dfs(int cur) {
    if (cur == deleteNode) return; // 삭제할 노드이면 종료
    
    if (edge[cur].empty()) { // 현재 노드가 리프 노드인지 확인
        answer++; // 리프 노드 개수 증가
        return;
    
    
    bool isLeaf = true;
    for (int next : edge[cur]) {
        if (next == deleteNode) continue; // 삭제할 노드는 건너뜀
        dfs(next);
        isLeaf = false;
    }
    
    if (isLeaf) answer++; // 자식이 모두 삭제되었을 경우 리프 노드로 판단
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0);
    cout.tie(0);
    
    int n, root = 0;
    cin >> n; // 노드 개수 입력
    edge.resize(n); // 인접 리스트 크기 설정
    
    // 트리 입력 받기
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < 0) {
            root = i; // 루트 노드 설정
        } else {
            edge[num].push_back(i); // 부모-자식 관계 저장
        }
    }
    cin >> deleteNode; // 삭제할 노드 입력
    
    dfs(root); // DFS 탐색 실행
    
    cout << answer << "\n"; // 리프 노드 개수 출력
    return 0;
}
