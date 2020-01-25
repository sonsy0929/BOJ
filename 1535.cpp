#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
int N, dp[21][101], H[21], D[21];
int f(int pos, int health) {
    if (pos == N) return 0;
    int &ret = dp[pos][health];
    if (ret != -1) return ret;
    if (health - H[pos] > 0) ret = f(pos + 1, health - H[pos]) + D[pos];
    return ret = max(ret, f(pos + 1, health));
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < 2 * N; i++) {
        if (i < N)
            scanf("%d", &H[i]);
        else
            scanf("%d", &D[i - N]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 100));
}