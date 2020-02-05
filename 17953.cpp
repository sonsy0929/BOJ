#include <bits/stdc++.h>
using namespace std;
int N, M, dp[10][100'000], dessert[10][100'000];
int f(int r, int c) {
    if (c == N) return 0;
    int &ret = dp[r][c];
    if (ret != -1) return ret;
    for (int i = 0; i < M; i++) {
        int satisfied = dessert[i][c];
        if (r == i) {
            ret = max(ret, f(i, c + 1) + satisfied / 2);
        } else {
            ret = max(ret, f(i, c + 1) + satisfied);
        }
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &dessert[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans = max(ans, f(i, 1) + dessert[i][0]);
    }
    printf("%d\n", ans);
}