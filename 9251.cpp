/*
LCS �˰���

�� ���ڿ��� ��� ���� �и��Ͽ� ���̺��� �����ϴ� ���� �ٽ�
���� ���, ���ڿ� s1�� ���ڿ� s2�� ������,
���ڿ� s1�� �࿡ s2�� ���� �ξ� ���̺��� �����Ѵ�.
�Ʒ��� ���� ���̺��� �����ϸ� �ͳ����� ���谡 ���̰� �ǰ� ��ȭ���� ���� �� �ִ�.

s1 = ACAYKP, s2 = CAPCAK�̸�
- 0 A C A Y K P
0 0 0 0 0 0 0 0
C 0 1 1 1 1 1 1
A 0 1 1 2 2 2 2  
P 0 1 2 2 2 2 3
C 0 1 2 2 2 2 3
A 0 1 2 3 3 3 3 
K 0 1 2 3 3 4 4

dp[i][j] = ������� ���ڿ� s1�� i���� ���� ���ڿ� s2�� j���� ������ ��, lcs ����
           s1[i] == s2[j]�̸� ���� �밢���� dp[i - 1][j - 1]�� +1�� ���ָ� lcs ���̸� ���� �� �ִ�
           �׷��� ������, (i - 1, j)�� (i, j - 1)�� �� �� �ִ밪�� lcs �����̴�.


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