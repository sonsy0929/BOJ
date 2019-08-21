#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N, C[5000], dp[5000][5000];
bool TURN;
int f(int l, int r){
    if (l > r) return 0;
    int &ret = dp[l][r];
    if (ret != -1) return ret;
    bool turn = (r - l) % 2 == TURN;
    if (turn) ret = max(f(l + 1, r) + C[l], f(l, r - 1) + C[r]);
    else ret = min(f(l + 1, r), f(l, r - 1));
    return ret;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", C + i);
    TURN = (N - 1) % 2;
    printf("%d\n", f(0, N - 1));
}