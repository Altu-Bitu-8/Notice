#include <iostream>
#include <set>
#include <vector>

using namespace std;

// 소수 여부 반환: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }

  return is_prime;
}

// 각 자리수의 제곱의 합 계산
int getSum(int n) {
  int total = 0, tmp;
  while (n != 0) {
    tmp = n % 10;  // 가장 마지막 자리 숫자 추출
    total += tmp * tmp;
    n /= 10;  // 가장 마지막 자리 숫자 없애기
  }
  return total;
}

// 상근수 여부 반환
bool checkValid(int n) {
  set<int> visited;  // 지금까지 나온 값을 저장하는 집합
  visited.insert(n);

  while (true) {
    n = getSum(n);  // 각 자리수 제곱의 합 구하기

    if (n == 1) {
      return true;
    }

    // 이전에 나온 적이 있는 값이면 상근수 아님
    if (visited.find(n) != visited.end()) {
      return false;
    }
    visited.insert(n);
  }
}

int main() {
  // 입력
  int n;
  cin >> n;

  // 연산 & 출력
  vector<bool> is_prime = getPrimes(n);

  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && checkValid(i)) {
      cout << i << '\n';
    }
  }

  return 0;
}
