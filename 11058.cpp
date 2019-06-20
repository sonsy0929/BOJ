#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[101];
int main(){
    int n;
    scanf("%d", &n);
    dp[1] = 1, dp[2] = 2, dp[3] = 3;
    for (int i = 4; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j < i; j++){
            dp[i] = max(dp[i], 1LL * dp[i - j] * (j - 1));
        }
    }
    printf("%lld\n", dp[n]);
}