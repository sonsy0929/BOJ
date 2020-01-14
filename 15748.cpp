#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int X[100'009],C[100'009];
int L, N, RF, RB;
int main(){
    scanf("%d %d %d %d", &L,&N,&RF,&RB);
    for (int i = 1; i <= N; i++){
        int r, x;
        scanf("%d %d", X+i,C+i);
    }
    int mx = 0, diff = RF-RB;
    ll ans = 0;
    for (int i = N; i > 0; i--){
        mx = max(mx,C[i]);
        ans += 1LL*(X[i]-X[i-1])*mx*diff;
    }
    printf("%lld\n", ans);
}