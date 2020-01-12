/*
O(N*M^3)
비트마스킹 연습하기 딱 좋은 문제 같다..

M개의 열 중 3개를 골랐을 때,
(i, j, k) ~ (ii, jj, kk) 간에 다른 set이라면
count++

*/
#include <cstdio>
#include <cstring>
using namespace std;
int N, M, Q[128], comb[64];
char s[1000][50];
int main(){
    scanf("%d %d", &N, &M);
    Q['A'] = 0, Q['C'] = 1, Q['G'] = 2, Q['T'] = 3;
    for (int i = 0; i < 2*N; i++) scanf(" %s", s[i]);
    int ans = 0;
    for (int i = 0; i < M; i++){
        for (int j = i+1; j < M; j++){
            for (int k = j+1; k < M; k++){
                memset(comb, false, sizeof(comb));
                bool ok = true;
                for (int p = 0; p < N; p++){
                    comb[Q[s[p][i]] * 16 + Q[s[p][j]] * 4 + Q[s[p][k]] * 1] = 1;
                }
                for (int p = N; p < 2*N; p++){
                    ok &= !comb[Q[s[p][i]] * 16 + Q[s[p][j]] * 4 + Q[s[p][k]] * 1];
                }
                if (ok) ans++;
            }
        }
    }
    printf("%d\n", ans);
}