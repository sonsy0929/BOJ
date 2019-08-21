#include <cstdio>
using namespace std;
using ll = long long;
const int SIZE = 10'001;
const int MOD = 1e9 + 7;
ll dp[SIZE][2];
int V[SIZE];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", V + i);
    if (V[0] == -1 || !V[0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    for (int i = 2; i <= N; i++){
        if (V[i] == -1){
            dp[0][1] = (dp[1][0] + dp[0][0]) % MOD;
            for (int j = 1; j <= N / 2; j++){
                dp[j][1] = (dp[j - 1][0] + dp[j][0] + dp[j + 1][0]) % MOD;
            }
        }
        else if (!V[i]) dp[0][1] = (dp[1][0] + dp[0][0]) % MOD;
        else{
            int h = V[i];
            dp[h][1] = (dp[h][0] + dp[h-1][0] + dp[h+1][0]) % MOD;
        }
        for (int i = 0; i <= N / 2; i++){
            dp[i][0] = dp[i][1];
            dp[i][1] = 0;
        }
    }
    printf("%lld\n", (V[N] == -1 || !V[N]) ? dp[0][0] : 0);
}