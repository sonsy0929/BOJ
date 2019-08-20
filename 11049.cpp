#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
using p = pair<int,int>;
const int INF = 1e9;
p H[501];
int dp[501][501];
int f(int L, int R){
    if (L == R) return 0;
    int &ret = dp[L][R];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = L; i < R; i++){
        ret = min(ret, f(L, i) + f(i + 1, R) + H[L].first * H[i].second * H[R].second);
    }
    return ret;
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        H[i].first = a;
        H[i].second = b;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(1, N));
}