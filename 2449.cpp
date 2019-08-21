#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int V[200], dp[200][200];
int f(int l, int r){
    if (l == r) return 0;
    int &ret = dp[l][r];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = l; i < r; i++){
        int cnt = (V[l] != V[i + 1]);
        ret = min(ret, f(l, i) + f(i + 1, r) + cnt);
    }
    return ret;
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d", V + i);
    printf("%d\n", f(0, n - 1));
}