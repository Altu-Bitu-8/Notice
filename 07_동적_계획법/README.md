# 동적계획법
[메인으로 돌아가기](https://github.com/Altu-Bitu-8/Notice) 
## 💻 튜터링 
### 라이브 코딩
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [2579](https://www.acmicpc.net/problem/2579) | [계단 오르기](https://www.acmicpc.net/problem/2579) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_동적_계획법/라이브코딩/2579.cpp) | 다이나믹 프로그래밍 |
| [14501](https://www.acmicpc.net/problem/14501) | [퇴사](https://www.acmicpc.net/problem/14501) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_동적_계획법/라이브코딩/14501.cpp) | 다이나믹 프로그래밍, 브루트포스 알고리즘 |
| [14002](https://www.acmicpc.net/problem/14002) | [가장 긴 증가하는 부분 수열 4](https://www.acmicpc.net/problem/14002) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_동적_계획법/라이브코딩/14002.cpp) | 다이나믹 프로그래밍 |
## ✏️ 과제 
### 마감기한
~ 4 / 4 (금) 18:59 - 과제 제출 </br>
~ 4 / 6 (일) 23:59 - 추가 제출 </br>
### 필수
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: |:--------------------------------------------------------------------------------------------------------------------------------------:| :-: |
| [11726](https://www.acmicpc.net/problem/11726) | [2 * n 타일링](https://www.acmicpc.net/problem/11726) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95/%ED%95%84%EC%88%98/11726.cpp) | 다이나믹 프로그래밍 |
| [11053](https://www.acmicpc.net/problem/11053) | [가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95/%ED%95%84%EC%88%98/11053.cpp) | 다이나믹 프로그래밍 |
| [20923](https://www.acmicpc.net/problem/20923) | [숫자 할리갈리 게임](https://www.acmicpc.net/problem/20923) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95/%ED%95%84%EC%88%98/20923.cpp) | 자료 구조, 덱, 구현, 시뮬레이션 |
### 도전
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: |:--------------------------------------------------------------------------------------------------------------------------------------:| :-: |
| [2240](https://www.acmicpc.net/problem/2240) | [자두나무](https://www.acmicpc.net/problem/2240) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95/%EB%8F%84%EC%A0%84/2240.cpp) | 다이나믹 프로그래밍 |
| [12865](https://www.acmicpc.net/problem/12865) | [평범한 배낭](https://www.acmicpc.net/problem/12865) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/> | [바로가기](https://github.com/Altu-Bitu-8/Notice/blob/main/07_%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95/%EB%8F%84%EC%A0%84/12865.cpp) | 다이나믹 프로그래밍 |
---
 ### 힌트
<details><summary>2 * n 타일링</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;가장 마지막 세로줄을 채울 수 있는 방법이 총 몇 가지 있나요? 잘 모르겠다면 n = 1 ~ 6까지 시뮬레이션 해봐요.</div></details>
<details><summary>가장 긴 증가하는 부분 수열</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;(dp[i] = 리스트의 i번째)를 마지막 값으로 가지는 가장 긴 부분 수열의 길이</div></details>
<details><summary>숫자 할리갈리 게임</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;카드를 어떤 자료구조로 관리하면 좋을까요? 게임을 반복해서 진행하네요. 함수화를 통해 효율적으로 코드를 작성할 수 있을 것 같아요! 덱이 비어있는 경우에 주의하세요!</div></details>
<details><summary>자두나무</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;초마다 자두를 먹을 수 있는 조건과 먹을 수 없는 조건을 생각해보면 좋을 것 같습니다!</div></details>
<details><summary>평범한 배낭</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;각 물건을 하나씩 확인하면서, 해당 물건을 넣었을 때와 넣지 않았을 때의 가치를 비교해가며 무게별 최대 가치를 채워나가 보세요.</div></details>

---
