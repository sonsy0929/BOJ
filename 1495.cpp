#include <cstdio>
using namespace std;
int v[101], dp[101][1001];
int main(){
    int n, s, m;
    scanf("%d %d %d", &n, &s, &m);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    int plus, minus;
    dp[0][s] = true;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (!dp[i - 1][j]) continue;
            plus = j + v[i];
            minus = j - v[i];
            if (plus <= m) dp[i][plus] = true;
            if (minus >= 0) dp[i][minus] = true;
        }
    }
    int ans = -1;
    for (int i = 0; i <= m; i++) {
        if (dp[n][i]) ans = i;
    }
    printf("%d\n", ans);
}