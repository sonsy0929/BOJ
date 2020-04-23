/*
시간복잡도 : O(N^3)

idea가 굉장히 중요한 문제였다. N = 5일 때를 생각해보자.
2 3 4 5 이런 식으로 건물이 나열이 되어있다고 생각해보면(L : 4, R : 1),
건물 1을 가장 앞과 가장 뒤에 놓아보자.

1 (2 3 4 5) => L : 5(= 4 + 1), R : 1
(2 3 4 5) 1 => L : 4, R : 2(= 1 + 1)

그 외의 자리에도 한번 놓아보면

2 1 3 4 5 => L과 R에 변화 X
2 3 1 4 5 => L과 R에 변화 X
...

위와 같이 '건물 1을 가장 나중에 놓는 방법'을 통해 L과 R의 변화를 쉽게 판단할 수 있다.
따라서, dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r] * (n - 2)
라는 점화식을 유추할 수 있다.
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