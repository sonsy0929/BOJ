#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100'001;
int uf[MAX], diff[MAX];
int find(int n){
    if (uf[n] < 0) return n;
    int pn = find(uf[n]);
    diff[n] += diff[uf[n]];
    return uf[n] = pn;
}
void merge(int u, int v, int w){
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;
    uf[pu] = pv;
    diff[pu] = diff[v] - diff[u] + w;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (; n != 0 || m != 0; scanf("%d %d", &n, &m)) {
        fill(uf, uf + MAX, -1);
        fill(diff, diff + MAX, 0);
        for (int i = 0; i < m; i++){
            char c; int a, b, w;
            scanf(" %c", &c);
            if (c == '!') {
                scanf("%d %d %d", &a, &b, &w);
                merge(a, b, w);
            }
            if (c == '?') {
                scanf("%d %d", &a, &b);
                if (find(a) != find(b)) puts("UNKNOWN");
                else printf("%d\n", diff[a] - diff[b]);
            }
        }
    }
}