#include <cstdio>
using namespace std;
const int MOD = 1e9;
int dp[101][10][1 << 10];
int main(){
    int n;
    scanf("%d", &n);
    for (int j = 1; j < 10; j++) dp[1][j][1 << j] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 1; k < 1 << 10; k++){
                int bit = 1 << j;
                if (j == 0) {
                    dp[i][j][k | bit] += dp[i - 1][j + 1][k];
                    dp[i][j][k | bit] %= MOD;
                }
                else if (j == 9) {
                    dp[i][j][k | bit] += dp[i - 1][j - 1][k];
                    dp[i][j][k | bit] %= MOD;
                }
                else {
                    dp[i][j][k | bit] += dp[i - 1][j - 1][k] % MOD + dp[i - 1][j + 1][k] % MOD;
                    dp[i][j][k | bit] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 10; j++) {
        ans += dp[n][j][1023];
        ans %= MOD;
    }
    printf("%d\n", ans);
}