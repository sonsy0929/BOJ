#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
const int SIZE = 100'000;
int N, M, Q, uf[SIZE];
vector<p> edge;
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    uf[u] += uf[v];
    uf[v] = u;
    return true;
}
int main(){
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        edge.push_back({u, v});
    }
    vector<int> qv;
    bool sliced[SIZE]{};
    for (int i = 0; i < Q; i++){
        int in;
        scanf("%d", &in);
        in--;
        qv.push_back(in);
        sliced[in] = true;
    }
    memset(uf, -1, sizeof(uf));
    for (int i = 0; i < M; i++){
        if (!sliced[i]) {
            int u, v;
            u = edge[i].first, v = edge[i].second;
            merge(u, v);
        }
    }
    ll ans = 0;
    for (int i = qv.size() - 1; i >= 0; i--){
        int order = qv[i];
        int u = edge[order].first, v = edge[order].second;
        int uCnt = abs(uf[find(u)]);
        int vCnt = abs(uf[find(v)]);
        if (merge(u, v)){
            ans += 1LL * uCnt * vCnt;
        }
    }
    printf("%lld\n", ans);
}