#include <algorithm>  // sort() 이용
#include <iostream>
#include <vector>

using namespace std;

// 최대공약수(GCD) 계산 함수: 유클리드 호제법 이용
int getGCD(int a, int b) {
  if (b == 0) {
    return a;
  }
  return getGCD(b, a % b);
}

// 가능한 M 검색 함수
vector<int> solution(int n, vector<int> &numbers) {
  vector<int> result;  // 가능한 M 저장

  // 1. 검문소 사이 간격의 최대공약수(최대 M) 계산
  // 연속한 두 검문소의 차이를 계산하기 위해 정렬
  sort(numbers.begin(), numbers.end());
  int gcd = numbers[1] - numbers[0];
  for (int i = 2; i < n; i++) {
    gcd = getGCD(gcd, numbers[i] - numbers[i - 1]);
  }

  // 2. 가능한 모든 M 찾기: 최대공약수의 약수 찾기
  for (int i = 2; i <= gcd; i++) {
    if (gcd % i == 0) {
      result.push_back(i);
    }
  }

  return result;
}

int main() {
  // 입력
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  // 연산
  vector<int> result = solution(n, numbers);

  // 출력
  for (int i : result) {
    cout << i << " ";
  }
  return 0;
}
