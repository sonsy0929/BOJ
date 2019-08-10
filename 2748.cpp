#include <cstdio>
#include <cstring>
using namespace std;
using ll = long long;
ll dp[100];
ll f(int k){
    if (k <= 0) return 0;
    if (k == 1) return 1;
    ll &ret = dp[k];
    if (ret != -1) return ret; 
    return ret = f(k - 1) + f(k - 2);
}
int main(){
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", f(n));
}