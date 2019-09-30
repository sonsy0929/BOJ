#include <cstdio>
using namespace std;
using ll = long long;
const int SIZE = 100'001;
ll pSum[SIZE], v[SIZE];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        scanf("%d", v+i);
        pSum[i] = pSum[i-1] + v[i];
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++){
        ans += v[i] * (pSum[N] - pSum[i]);
    }
    printf("%lld", ans);
}