// 2343: 기타 레슨 (실버 1/이분 탐색, 매개 변수 탐색)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
* 적절한 블루레이의 크기를 매개변수 탐색을 이용해 찾습니다.
* 이 때, 각 블루레이의 크기는 최대 강의 길이(maxLen) 이상, 강의 길이의 총합(sumLen) 이하임을 이용합니다.
*/

int countBlueray(int n, int mid, vector<int> &lesson){
	int count = 1;    // 블루레이의 개수
	int sum_blue = 0; // 현재 블루레이에 들어간 총 강의 길이
	for (int i = 0; i < n; i++) {
		if (sum_blue + lesson[i] > mid) {
			count++; 
      sum_blue = 0;
    }
    sum_blue += lesson[i];
  }
  return count;
}

int findSize(int &left, int right, vector<int> &lesson, int n, int m) {
    // 적절한 블루레이의 크기를 이진탐색을 이용해 찾기
    while (left <= right) {
        int mid = (left + right) / 2; // mid(찾는 값): 블루레이 크기 후보
        
        // 사이즈가 mid일 때의 블루레이 개수가 m보다 작거나 같으면 더 작은 사이즈로 가정하고 탐색
        // 반대의 경우, 더 큰 값으로 가정하고 탐색
        int count = countBlueray(n, mid, lesson);
		    (count <= m) ? right = mid - 1 : left = mid + 1;
    }
    return left;
}

int main() {
    int n, m, sum_len = 0, max_len = 0; // 강의의 수, 블루레이의 수 

    // 입력
    cin >> n >> m;
    vector<int> lesson(n); // 강의 동영상의 길이를 입력받을 벡터

    // 강의 동영상의 길이 입력
    for (int i = 0; i < n; i++) {
        cin >> lesson[i];
        sum_len += lesson[i];              // 강의 길이의 합 갱신 (right)
        max_len = max(lesson[i], max_len); // 강의 길이의 최댓값 갱신 (left)
    }    

    // 연산 & 출력
    cout << findSize(max_len, sum_len, lesson, n, m);
    
    return 0;
}