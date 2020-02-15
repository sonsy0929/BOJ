/*
시간 복잡도 : O(NT)

그냥 평범한 냅색 문제
*/
#include <bits/stdc++.h>
using namespace std;
int N, T, dp[100][10010], _time[100], score[100];
int f(int pos, int t) {
    if (pos == N) return 0;
    int &ret = dp[pos][t];
    if (ret != -1) return ret;
    ret = f(pos + 1, t);
    if (t - _time[pos] >= 0) ret = max(ret, f(pos + 1, t - _time[pos]) + score[pos]);
    return ret;
}
int main() {
    scanf("%d %d", &N, &T);
    for (int i = 0; i < N; i++) {
        int K, S;
        scanf("%d %d", &K, &S);
        _time[i] = K;
        score[i] = S;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, T));
}