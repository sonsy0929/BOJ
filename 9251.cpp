/*
LCS 알고리즘

각 문자열을 행과 열로 분리하여 테이블을 구성하는 것이 핵심
예를 들어, 문자열 s1과 문자열 s2가 있으면,
문자열 s1은 행에 s2는 열에 두어 테이블을 구성한다.
아래와 같이 테이블을 구성하면 귀납적인 관계가 보이게 되고 점화식을 세울 수 있다.

s1 = ACAYKP, s2 = CAPCAK이면
- 0 A C A Y K P
0 0 0 0 0 0 0 0
C 0 1 1 1 1 1 1
A 0 1 1 2 2 2 2  
P 0 1 2 2 2 2 3
C 0 1 2 2 2 2 3
A 0 1 2 3 3 3 3 
K 0 1 2 3 3 4 4

dp[i][j] = 현재까지 문자열 s1을 i까지 보고 문자열 s2를 j까지 보았을 때, lcs 길이
           s1[i] == s2[j]이면 왼쪽 대각선의 dp[i - 1][j - 1]에 +1을 해주면 lcs 길이를 구할 수 있다
           그렇지 않으면, (i - 1, j)나 (i, j - 1)의 값 중 최대값이 lcs 길이이다.


*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1001;
char s1[MAX], s2[MAX];
int dp[MAX][MAX];
int main(){
    scanf("%s %s", s1 + 1, s2 + 1);
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
}