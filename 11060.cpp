#include <cstdio>
#include <algorithm>
using namespace std;
int N, dp[1001], in[1001];
const int INF = 0x3f3f3f3f;
int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", in + i);
    fill(dp, dp + 1001, INF);
    dp[1] = 0;    
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= in[i]; j++){
            if (i + j > N) continue;
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    printf("%d\n", dp[N] != INF ? dp[N] : -1);
}