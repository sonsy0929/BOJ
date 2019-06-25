#include <cstdio>
#include <cstring>
using namespace std;
int n, S[2000], dp[2000][2000];
int f(int i, int j){
    if (i == j) return 1;
    if (i + 1 == j && S[i] == S[j]) return 1;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    if (S[i] != S[j]) return ret = 0;
    return ret = f(i + 1, j - 1);
}
int main(){
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d", S + i);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        s--, e--;
        printf("%d\n", f(s, e));
    }
}