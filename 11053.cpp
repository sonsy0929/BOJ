#include <cstdio>
#include <algorithm>
using namespace std;
int v[1001], dp[1001];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
}