#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int card[1001], dp[1001][1001][2];
int f(int l, int r, bool turn){
    if (l > r) return 0;
    int &ret = dp[l][r][turn];
    if (ret != -1) return ret;
    ret = 0;
    if (turn) ret = max(f(l + 1, r, false) + card[l], f(l, r - 1, false) + card[r]);
    else ret = min(f(l + 1, r, true), f(l, r - 1, true));
    return ret;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", card + i);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", f(0, N - 1, true));
    }
}