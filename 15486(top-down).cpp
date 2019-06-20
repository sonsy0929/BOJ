// top-down

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1'500'001;
int N, T[MAX], P[MAX], dp[MAX];
int f(int pos){
    if (pos > N) return 0;
    int &ret = dp[pos];
    if (ret != -1) return ret;
    ret = f(pos + 1);
    if (pos + T[pos] <= N + 1) ret = max(ret, f(pos + T[pos]) + P[pos]);
    return ret;
}
int main(){
    scanf("%d", &N);
    fill(dp, dp + MAX, -1);
    for (int i = 1; i <= N; i++) scanf("%d %d", T + i, P + i);
    printf("%d\n", f(1));
}