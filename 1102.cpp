#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 1 << 17;
const int INF = 0x3f3f3f3f;
int W[16][16], dp[SIZE];
char stat[16];
int main(){
    int N, P;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &W[i][j]);
        }
    }
    scanf(" %s %d", stat, &P);
    int currState = 0, cnt = 0;
    for (int i = 0; i < N; i++){
        if (stat[i] == 'Y') {
            currState += 1 << i;
            cnt++;
        }
    }
    if (cnt >= P) {
        puts("0");
        return 0;
    }
    memset(dp, INF, sizeof(dp));
    int ans = INF;
    dp[currState] = 0;
    for (int i = currState; i < (1 << N); i++){
        cnt = 0;
        for (int j = 0; j < N; j++){
            if (i & (1 << j)){
                for (int k = 0; k < N; k++){
                    if (i & (1 << k)) continue;
                    dp[i + (1 << k)] = min(dp[i + (1 << k)], dp[i] + W[j][k]);
                }
                cnt++;
            }
        }
        if (cnt >= P) ans = min(ans, dp[i]);
    }
    printf("%d\n", ans != INF ? ans : -1);
}