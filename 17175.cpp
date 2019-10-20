#include <cstdio>
using namespace std;
int dp[55];
const int MOD = 1e9 + 7;
int main(){
    int n;
    scanf("%d", &n);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-2] % MOD + dp[i-1] % MOD + 1;
        dp[i] %= MOD;
    }
    printf("%d\n", dp[n]);
}