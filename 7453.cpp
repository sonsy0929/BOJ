#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N, top;
ll A[4000][4];
ll sum[2][16000000];
void getSum(int u, int v, int idx){
    top = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            sum[idx][top++] = A[i][u] + A[j][v];
        }
    }
}
ll solve(int u, int v){
    ll ret = 0;
    for (int i = 0; i < top; i++){
        ll val = sum[u][i];
        auto iter_lo = lower_bound(sum[v], sum[v] + top, -val);
        auto iter_hi = upper_bound(sum[v], sum[v] + top, -val);
        if (*iter_lo != -val) continue;
        ret += iter_hi - iter_lo; 
    }
    return ret;
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 4; j++){
            scanf("%lld", &A[i][j]);
        }
    }
    getSum(0, 1, 0);
    getSum(2, 3, 1);
    for (int i = 0; i < 2; i++) sort(sum[i], sum[i] + top);
    ll ans = solve(0, 1);
    printf("%lld\n", ans);
}