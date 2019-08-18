#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 100'000;
int w, h, dp[100][100][2][2];
int f(int r, int c, int prev, int rotate){
    if (r >= h || c >= w) return 0;
    if (r == h - 1 && c == w - 1) return 1;
    int &ret = dp[r][c][prev][rotate];
    if (ret != -1) return ret;
    ret = 0;
    if (!rotate) {
        if (!prev) ret = f(r + 1, c, 0, 0) + f(r, c + 1, 1, 1);
        else ret = f(r + 1, c, 0, 1) + f(r, c + 1, 1, 0);
    }
    else {
        if (!prev) ret = f(r + 1, c, 0, 0);
        else ret = f(r, c + 1, 1, 0);
    }
    return ret % MOD;
}
int main(){
    scanf("%d %d", &w, &h);    
    memset(dp, -1, sizeof(dp));
    int ans = f(1, 0, 0, 0) + f(0, 1, 1, 0);
    printf("%d\n", ans % MOD);
}