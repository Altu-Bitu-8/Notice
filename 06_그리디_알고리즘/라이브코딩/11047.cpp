#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	vector<int> A(n, 0);
	
	// 동전 가치 입력
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	while (n--) { // 큰 가치부터 검사하기 (동전 개수의 '최솟값'을 구해야하므로)
        cnt += k / A[n];
        k %= A[n];
    }
	
	cout << cnt;
	return 0;
}
