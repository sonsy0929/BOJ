#include <cstdio>
#include <algorithm>
using namespace std;
int step[301], dp[301];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", step + i);
    dp[1] = step[1];
    dp[2] = step[1] + step[2];
    for (int i = 3; i <= N; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + step[i - 1]) + step[i];
    }
    printf("%d\n", dp[N]);
}