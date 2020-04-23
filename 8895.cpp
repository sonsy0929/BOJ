/*
�ð����⵵ : O(N^3)

idea�� ������ �߿��� ��������. N = 5�� ���� �����غ���.
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
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
int N, L, R, T;
ll dp[23][23][23];
ll f(int n, int l, int r) {
    if (n == 1) return l == 1 && r == 1;
    ll &ret = dp[n][l][r];
    if (ret != -1) return ret;
    ret = f(n-1,l,r-1)+f(n-1,l-1,r)+(n-2)*f(n-1,l,r);
    return ret;
}
int main() {
    fastio;
    memset(dp, -1, sizeof(dp));
    for (cin >> T; T--;) {
        cin >> N >> L >> R;
        cout << f(N, L, R) << "\n";
    }
}