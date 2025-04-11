#include<iostream>

using namespace std;

int graph[101][101] = {0,}; // 그래프
int visited[101] = {false, }; // 방문 여부
int p1, p2; // 촌수를 계산해야하는 서로 다른 두 사람의 번호

int n; //전체 사람의 수
int m; // 부모 자식들 간의 관계의 개수

int dfs(int from) {

	int ret = -1;

	if (graph[from][p2] == 1) {
		return 1;
	}

	else {
		for (int i = 1; i <= n; ++i) {
			if (i == from) {
				continue; // 자기를 참조할 때는 건너뜀
			}
			if (graph[from][i] == 1 && !visited[i]) { // 사람이 연결 되어있고, 참조하지 않은 사람이라면 dfs 함수 호출
				visited[i] = true;
				ret = max(ret, dfs(i));
			}
		}
	}
	if (ret != -1) {
		ret += 1;
	}
	return ret;

}

int main() {
	cin >> n;
	cin >> p1 >> p2;
	cin >> m;

	for (int i = 0; i < m; ++i) { // 부모 자식간의 관계의 개수 m 개 입력
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
	}

	int ans = dfs(p1); // dfs 함수 호출
	cout << ans;
}
