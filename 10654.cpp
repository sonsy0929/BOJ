#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    int N, T;
    scanf("%d %d", &N, &T);
    vector<ll> v(1, -1);
    for (int i = 0; i < N; i++){
        int p, s;
        scanf("%d %d", &p, &s);
        v.push_back(p + 1LL * s * T);
    }
    ll prev = v.back();
    int ans = 0;
    for (int i = v.size() - 1; i >= 0; i--){
        if (v[i] < prev) ans++;
        prev = min(prev, v[i]);
    }
    printf("%d\n", ans);
}