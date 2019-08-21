#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int N, W[16][16], dp[16][1<<16];
int f(int curr, int visited){
    int &ret = dp[curr][visited];
    if (ret != -1) return ret;
    if (visited == (1 << N) - 1){
        if (W[curr][0]) return W[curr][0];
        return INF;
    }
    ret = INF;
    for (int i = 0; i < N; i++){
        if (visited & (1 << i) || !W[curr][i]) continue;
        ret = min(ret, f(i, visited | (1 << i)) + W[curr][i]);
    }
    return ret;
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &W[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 1));
}