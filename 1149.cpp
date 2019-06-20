#include <cstdio>
#include <algorithm>
using namespace std;
int price[1001][4];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++){
            scanf("%d", &price[i][j]);
        }
    }
    int dp[1001][4]{};
    for (int i = 1; i <= n; i++){
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + price[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + price[i][2];
        dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + price[i][3];
    }
    int ans = 1e9;
    for (int i = 1; i <= 3; i++) ans = min(ans, dp[n][i]);
    printf("%d\n", ans);
}