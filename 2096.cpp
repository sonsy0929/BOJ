#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[3][2], _prev[3][2];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int in[3]{};
        for (int j = 0; j < 3; j++){
            scanf("%d", in + j);
        }
        dp[0][0] = max(_prev[0][0] + in[0], _prev[1][0] + in[0]);
        dp[0][1] = min(_prev[0][1] + in[0], _prev[1][1] + in[0]);
        dp[1][0] = max({_prev[0][0] + in[1], _prev[1][0] + in[1], _prev[2][0] + in[1]});
        dp[1][1] = min({_prev[0][1] + in[1], _prev[1][1] + in[1], _prev[2][1] + in[1]});
        dp[2][0] = max(_prev[1][0] + in[2], _prev[2][0] + in[2]);
        dp[2][1] = min(_prev[1][1] + in[2], _prev[2][1] + in[2]);
        memcpy(_prev, dp, sizeof(_prev));
    }
    int mx = 0, mn = 1e9;
    for (int i = 0; i < 3; i++){
        mx = max(mx, dp[i][0]);
        mn = min(mn, dp[i][1]);
    }
    printf("%d %d\n", mx, mn);
}