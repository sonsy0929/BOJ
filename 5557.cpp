#include <cstdio>
#include <cstring>
using namespace std;
using ll = long long;
int v[100], N;
ll dp[100][21];
ll f(int pos, int sum){
    if (sum < 0 || sum > 20) return 0;
    ll &ret = dp[pos][sum];
    if (ret != -1) return ret;
    if (pos == N - 1) return sum == v[N - 1];
    return ret = f(pos + 1, sum + v[pos]) + f(pos + 1, sum - v[pos]);
}
int main(){
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) scanf("%d", v + i);
    printf("%lld\n", f(1, v[0]));
}