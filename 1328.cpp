/*
�ð����⵵ : O(N^3)

idea�� ������ �߿��� ��������.
������ ���ÿ� ���� N = 5�� ���� �����غ���.
2 3 4 5 �̷� ������ �ǹ��� ������ �Ǿ��ִٰ� �����غ���(L : 4, R : 1),
�ǹ� 1�� ���� �հ� ���� �ڿ� ���ƺ���.

1 (2 3 4 5) => L : 5(= 4 + 1), R : 1
(2 3 4 5) 1 => L : 4, R : 2(= 1 + 1)

�� ���� �ڸ����� �ѹ� ���ƺ���

2 1 3 4 5 => L�� R�� ��ȭ X
2 3 1 4 5 => L�� R�� ��ȭ X
...

���� ���� '�ǹ� 1�� ���� ���߿� ���� ���'�� ���� L�� R�� ��ȭ�� ���� �Ǵ��� �� �ִ�.
����, dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r] * (n - 2)
��� ��ȭ���� ������ �� �ִ�.
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp[101][101][101];
int f(int n, int l, int r) {
    if (n == 1) return l == 1 && r == 1;
    int& ret = dp[n][l][r];
    if (ret != -1) return ret;
    ret = f(n - 1, l - 1, r) + f(n - 1, l, r - 1) % MOD;
    ret = (ret + (1LL * f(n - 1, l, r) * (n - 2))) % MOD;
    return ret;
}
int main() {
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);
    memset(dp, -1, sizeof(dp));
    printf("%d", f(N, L, R));
}