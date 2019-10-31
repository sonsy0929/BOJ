#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int MAXSIZE = 10'000;
int N, M, money, cost[MAXSIZE], uf[MAXSIZE];
bool used[MAXSIZE];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (cost[u] > cost[v]) swap(u, v);
    uf[v] = u;
}
int main(){
    memset(uf, -1, sizeof(uf));
    scanf("%d %d %d", &N, &M, &money);
    for (int i = 0; i < N; i++) scanf("%d", cost+i);
    int u, v;
    for (int i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        merge(u-1, v-1);
    }
    int ans = 0;
    for (int i = 0; i < N; i++){
        v = find(i);
        if (uf[v] < 0){
            if (!used[v]) ans += cost[v];
            used[v] = true;
        } 
    }
    if (ans > money) puts("Oh no");
    else printf("%d\n", ans);
}