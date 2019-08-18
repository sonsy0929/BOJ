#include <cstdio>
using namespace std;
const int MOD = 10'007;
int dp[1001][1001];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;   
        }
    }
    printf("%d\n", dp[n][k]);
}