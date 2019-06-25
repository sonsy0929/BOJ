#include <cstdio>
using namespace std;
int N, S[2000], dp[2000][2000];
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", S + i);
    for (int i = 0; i < N; i++) dp[i][i] = 1;
    for (int i = 0; i < N - 1; i++){
        if (S[i] == S[i + 1]) dp[i][i + 1] = 1;
    }
    for (int l = 2; l < N; l++){
        for (int i = 0; i < N - l; i++){
            int j = i + l;
            if (S[i] != S[j]) dp[i][j] = 0;
            else dp[i][j] = dp[i + 1][j - 1];
        }
    }
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        printf("%d\n", dp[a][b]);
    }
}