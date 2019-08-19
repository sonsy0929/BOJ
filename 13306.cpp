#include <cstdio>
#include <cstring>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 200'001;
int uf[SIZE], pa[SIZE];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return;
    uf[v] = u;
}
int main(){
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N - 1; i++){
        int in;
        scanf("%d", &in);
        pa[i + 1] = in;
    }
    Q = (N - 1) + Q;
    vector<p> qv;
    for (int i = 0; i < Q; i++){
        int x;
        scanf("%d", &x);
        if (x){
            int c, d;
            scanf("%d %d", &c, &d);
            qv.push_back({c, d});
        }
        else{
            int b;
            scanf("%d", &b);
            qv.push_back({b, 0});
        }
    }
    memset(uf, -1, sizeof(uf));
    vector<int> res;
    for (int i = qv.size() - 1; i >= 0; i--){
        int u, v;
        tie(u, v) = qv[i];
        if (!v) merge(u, pa[u]);
        else {
            if (find(u) == find(v)) res.push_back(1);
            else res.push_back(0);
        }
    }
    reverse(res.begin(), res.end());
    for (int curr : res){
        if (curr) puts("YES");
        else puts("NO");
    }
}