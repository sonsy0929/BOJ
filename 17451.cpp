#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
ll v[300'000]; int n;
bool isPossible(ll m){
    bool ret = true;
    ll k = m;
    for (int i = 0; i < n; i++){
        ret &= (k / v[i] > 0);
        if (k % v[i]) k = v[i] * (k / v[i]);
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", v+i);
    ll lo = 0, hi = 1e18;
    while (lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if (isPossible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%lld\n", hi);
}