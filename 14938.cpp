#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(){
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int item[100]{}, dist[100][100]{};
    for (int i = 0; i < n; i++) scanf("%d", item + i);
    memset(dist, INF, sizeof(dist));
    for (int i = 0; i < r; i++){
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        dist[u - 1][v - 1] = k;
        dist[v - 1][u - 1] = k;
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        int cnt = item[i];
        for (int j = 0; j < n; j++){
            if (i == j || dist[i][j] > m) continue;
            cnt += item[j];
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}