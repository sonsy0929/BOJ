#include <cstdio>
#include <algorithm>
using namespace std;
int M, N, farm[1001][1001], dp[1001][1001];
int main(){
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            scanf("%d", &farm[i][j]);
        }
    }
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            if (!farm[i][j]){
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
}