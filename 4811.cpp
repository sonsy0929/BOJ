#include <bits/stdc++.h>
using namespace std;
int N;
long long dp[31][31];
long long f(int w, int h) {
    if (w < 0 || h < 0) return 0;
    if (w == 0 && h == 0) return 1;
    long long &ret = dp[w][h];
    if (ret != -1) return ret;
    return ret = f(w - 1, h + 1) + f(w, h - 1);
}
int main() {
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", f(N, 0));
    }
}