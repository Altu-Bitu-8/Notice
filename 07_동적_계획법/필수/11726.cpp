#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

int countCases(int n) {
	// dp[i]: 2 x i 크기의 직사각형을 채우는 방법의 수
	vector<int> dp(n + 1);

	dp[1] = 1; // 세로로 한 개
	dp[2] = 2; // 세로로 두 개 or 가로로 두 개

	for (int i = 3; i <= n; i++) {
		int vertical = dp[i - 1]; // 세로로 한 개 놓는 경우
		int horizontal = dp[i - 2]; // 가로로 두 개 놓는 경우
		dp[i] = (vertical + horizontal) % MOD; // 오버플로우 방지를 위해 MOD 연산
	}
	return dp[n];
}

/*
가장 마지막 세로줄을 채울 수 있는 방법을 살펴봅시다.
1. 세로로 한 개를 놓는다.
2. 가로로 두 개를 놓는다.

1번 방법으로 마지막 세로줄을 채울 경우, 남은 부분의 크기는 2 x (n-1)
2번 방법으로 마지막 세로줄을 채울 경우, 남은 부분의 크기는 2 x (n-2)

따라서 2 x n 크기의 직사각형을 채우는 방법의 수는
d[i] = dp[i - 1] + dp[i - 2]
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    // 입력
	int n;
	cin >> n;

	// 연산 & 출력
	cout << countCases(n);

	return 0;
}