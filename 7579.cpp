#include <cstdio>
#include <algorithm>
using namespace std;
int dp[101][10001];
int memory[101], cost[101];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", memory + i);
    for (int i = 1; i <= N; i++) scanf("%d", cost + i);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= 100 * N; j++){
            if (j >= cost[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]
            );
            else dp[i][j] = dp[i-1][j];
        }
    }
    int ans = 1e9;
    for (int j = 1; j <= 100 * N; j++){
        if (dp[N][j] >= M) ans = min(ans, j);
    }
    printf("%d\n", ans);
}