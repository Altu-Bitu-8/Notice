#include<iostream>
#include<queue> // for bfs
#include<cstring> // for memset (visited 배열 초기화)

using namespace std;

int n;
int m;
int v;
int graph[1001][1001] = { 0, }; // 그래프 배열
bool visited[10001] = {false, }; // 방문 배열
int dfs_answer[1001] = {0, }; // dfs 정답을 담을 배열
int bfs_answer[1001] = {0, }; // bfs 정답을 담을 배열
int idx = 1;


void dfs(int from) {
	for (int i = 1; i <= n; ++i) {
		if (graph[from][i] == 1 && !visited[i]) {
			visited[i] = true;
			dfs_answer[idx++] = i; // idx 에 해당하는 위치에 정답을 저장하고 idx 에 1을 더해줍니다
			dfs(i);
		}
	}
	return;
}

// bfs 만 있는 문제는 메인 함수 내에서 사용해도 되지만, dfs 와 함께 쓰므로 가독성을 위해 함수로 따로 뺐습니다.
void bfs(int from) { 
	queue<int> q;
	q.push(from);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (graph[now][i] == 1 && !visited[i]) {
				visited[i] = true;
				bfs_answer[idx++] = i;
				q.push(i);
			}
		}
	}

	return;
}

void reset() {
	memset(visited, false, sizeof(visited)); // bfs 를 하기 위해 visited 배열을 초기화 해줍니다.
	visited[v] = true;
	idx = 1;
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
	}

	
	dfs_answer[0] = bfs_answer[0] = v; // 항상 v 를 첫번째로 지나므로 0번째 배열에 v 를 담습니다.

	visited[v] = true;
	dfs(v);

	reset();
	bfs(v);

	for (int i = 0; i < n; ++i) {
		if (dfs_answer[i] == 0) {
			break;
		}
		else {
			cout << dfs_answer[i] << " ";
		}
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		if (bfs_answer[i] == 0) {
			break;
		}
		else {
			cout << bfs_answer[i] << " ";
		}
	}
}
