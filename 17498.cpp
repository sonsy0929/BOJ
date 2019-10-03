#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 2e9+10;
const int SIZE = 200'010;
int N, M, D, score[SIZE], dp[SIZE];
bool isPossible(int r, int c){
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}
int f(int n){
    int &ret = dp[n];
    if (ret != -INF) return ret;
    int r = n / M, c = n % M;
    if (r == N-1) return 0;
    ret = -INF;
    for (int i = 1; i <= D; i++){
        for (int j = -D-1; j <= D-1; j++){
            int nr = r + i, nc = c + j;
            if (!isPossible(nr, nc) || i + abs(j) > D) continue;
            ret = max(ret, f(nr*M+nc)+score[r*M+c]*score[nr*M+nc]);
        }
    }
    return ret;
}
int main(){
    scanf("%d %d %d", &N, &M, &D);
    fill(dp, dp+SIZE, -INF);
    for (int i = 0; i < N * M; i++) scanf("%d", score+i);
    int ans = -INF;
    for (int i = 0; i < M; i++){
        ans = max(ans, f(i));
    }
    printf("%d", ans);
}