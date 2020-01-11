#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int INF = 0x3f3f3f3f;
int dist[51][51];
int main(){
    int n;
    scanf("%d", &n);
    memset(dist, INF, sizeof(dist));
    while (1){
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1) break;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int ans = INF, mx = 0, len = 0;
    int ansList[51]{};
    for (int i = 1; i <= n; i++){
        mx = 0;
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            if (dist[i][j] != INF) mx = max(mx, dist[i][j]);
        }
        if (ans >= mx){
            if (ans != mx) len = 0;
            ansList[len++] = i;
            ans = mx;
        }
    }
    printf("%d %d\n", ans, len);
    for (int i = 0; i < len; i++) printf("%d ", ansList[i]);
}