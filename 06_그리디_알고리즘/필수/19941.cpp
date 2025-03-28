#include <iostream>
#include <string>
using namespace std;

int countHamburgers(int n, int k, string& str) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != 'P') {
            continue;
        }
        
        // 사람 P(i)를 기준으로 -k ~ k 범위 탐색
        for(int j = i - k; j <= i + k; j++) {
            if(j < 0 || j > n - 1) {
                continue;
            }

            if (str[j] == 'H') { // 햄버거가 있으면 카운트 증가
                cnt++;
                str[j] = '.'; // 먹은 햄버거는 . 처리
                break;
            }
        }
    }
    return cnt;
}

int main() {
    int n, k;
    string s;
    
    cin >> n >> k >> s;
    cout << countHamburgers(n, k, s) << "\n";
    
    return 0;
}
