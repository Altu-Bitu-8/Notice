#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/*
1. 가능한 모든 부분 문자열을 생성
2. 생성한 문자열을 set에 집어넣기
3. set의 크기를 출력 (set에는 중복된 원소가 포함될 수 없으므로 서로 다른 부분 문자열만이 안에 저장됨.)
 */

// 부분 문자열을 생성한 뒤 이를 set에 넣고 set의 크기를 리턴하는 함수
int checkSubString(string str) {
    set<string> s;
    int len = str.length(); // 반복문에서 매번 length 함수를 호출하지 않기 위해 선언해두기

    /*
    substr 함수 : str.substr(pos, len)
    pos는 부분 문자열이 시작하는 위치, len은 문자열의 길이를 의미함.
    */

    for (int i = 0; i < len; i++) {
        for (int j = len - i; j >= 1; j--) { // pos가 앞으로 당겨진 만큼 부분 문자열의 최대 길이가 감소.
            string substr = str.substr(i, j);
            s.insert(substr);
        }
    }

    return s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    // 입력
    cin >> str;
    
    // 출력
    cout << checkSubString(str);
}