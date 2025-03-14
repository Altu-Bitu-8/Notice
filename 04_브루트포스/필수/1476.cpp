// 1476: 날짜 계산 (실버5/브루트포스)
#include <iostream>

using namespace std;

int solve(int earth, int sun, int moon)
{
    if (earth == 15)
        earth = 0;
    if (sun == 28)
        sun = 0;
    if (moon == 19)
        moon = 0;
    // 행성의(지구, 태양, 달) 범위에 해당하면 0으로 바꾸어준다.
    // 아래 비교문에서 mod 연산을 사용했기 때문에 이를 고려한다.

    int year = 1;
    while (true)
    {
        if (year % 15 == earth && year % 28 == sun && year % 19 == moon)
        {
            return year;
        }
        year++;
    }
}

int main()
{
    // 입력
    int e, s, m;
    cin >> e >> s >> m;

    // 연산 & 출력
    cout << solve(e, s, m);

    return 0;
}
