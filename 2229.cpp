#include <bits/stdc++.h>
using namespace std;
int N, dp[1000], score[1000];
int f(int pos) {
    if (pos >= N) return 0;
    int &ret = dp[pos];
    if (ret != -1) return ret;
    int mx = 0, mn = 1e9;
    for (int i = pos; i < N; i++) {
        mx = max(mx, score[i]);
        mn = min(mn, score[i]);
        ret = max(ret, f(i + 1) + mx - mn);
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", score + i);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0));
}