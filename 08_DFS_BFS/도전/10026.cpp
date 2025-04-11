#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n;
char graph[100][100];
bool visit[100][100];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void dfs2(int y, int x, char c) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < n && nx>=0 && nx < n) {
			if (!visit[ny][nx]) {
				if ((c == 'R' || c == 'G' )&& (graph[ny][nx]=='R' || graph[ny][nx]=='G')) {
					visit[ny][nx] = true;
					dfs2(ny, nx, c);
				}
				else if (c == 'B') {
					if (graph[ny][nx] == 'B') {
						visit[ny][nx] = true;
						dfs2(ny, nx, c);
					}
				}
			}
		}
	}
}

void dfs(int y, int x, char c) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < n && nx>=0 && nx < n) {
			if (!visit[ny][nx] && graph[ny][nx] == c) {
				visit[ny][nx] = true;
				dfs(ny, nx, c);
			}
		}
	}
}
	
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			graph[i][j] = s[j];
		}
	}
	int ans1 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) {
				ans1++;
				dfs(i, j, graph[i][j]);
				visit[i][j] = true;
			}
		}
	}

	memset(visit, false, sizeof(visit));

	int ans2 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) {
				ans2++;
				dfs2(i, j, graph[i][j]);
			}
		}
	}
	cout << ans1 << " " << ans2;
}
