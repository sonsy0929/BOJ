#include <cstdio>
#include <algorithm>
using namespace std;
int map[501][501], dp[501][501];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            scanf("%d", &map[i][j]);
        }
    }
    dp[1][1] = map[1][1];
    for (int i = 2; i <= N; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + map[i][j];
        }
    }
    int ans = 0;
    for (int j = 1; j <= N; j++) ans = max(ans, dp[N][j]);
    printf("%d\n", ans);
}