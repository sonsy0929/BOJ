#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using tup = tuple<int,int,int>;
constexpr int MAXSIZE = 200'000;
int m, n, uf[MAXSIZE];
tup Edge[MAXSIZE];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    uf[u] = v;
    return true;
}
int main(){
    while(1){
        scanf("%d %d", &m, &n);
        if (!m && !n) break;
        int x, y, z, sum = 0;
        fill(uf, uf + MAXSIZE, -1);
        for (int i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &z);
            Edge[i] = {z, x, y};
            sum += z;
        }
        sort(Edge, Edge + n);
        int cost = 0, edgeCnt = n - 1;
        for (int i = 0; i < n; i++){
            int u, v, w;
            tie(w, u, v) = Edge[i];
            if (merge(u, v)){
                cost += w;
                if (--edgeCnt == 0) break;
            }
        }
        printf("%d\n", sum - cost);
    }
}