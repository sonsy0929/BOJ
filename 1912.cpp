#include <cstdio>
#include <algorithm>
using namespace std;
int dp[100'001], v[100'001];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    dp[1] = v[1];
    for (int i = 2; i <= n; i++) dp[i] = max(0, dp[i - 1]) + v[i];
    int ans = -1e9;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
}