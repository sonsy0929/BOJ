// bottom up

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1'500'002;
int N, dp[MAX];
int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        int t, p;
        scanf("%d %d", &t, &p);
        dp[i + 1] = max(dp[i], dp[i + 1]);
        if (i + t <= N + 1) dp[i + t] = max(dp[i + t], dp[i] + p);
    }
    printf("%d\n", dp[N + 1]);
}