#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//입력받은 배열을 받아 최소 속도를 계산해 리턴하는 함수
long long calculateMinSpeed(int n, const vector<int>& v) {
	long long v_min = v[n - 1];

	// 뒤에서부터 탐색하며 최소 시작 속도를 계산
	for (int i = n - 2; i >= 0; --i) {
		// 최소 속도보다 v[i]가 클 때 
		if (v_min < v[i]) {
			v_min = v[i]; // 최소 속도를 업데이트 한다 
		}
		// 최소 속도보다 v[i]가 작을 때
		// v_min 값을 필요한 속도 * 정수 배(m)가 되도록 업데이트 한다 
		long long m = ceil((double)v_min / v[i]);
		v_min = v[i] * m;
	}

	return v_min;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	cout << calculateMinSpeed(n, v) << "\n";
	
	return 0;
}
