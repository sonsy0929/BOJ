#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    int connect[501][501]{};
    memset(connect, INF, sizeof(connect));
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        connect[u][v] = 1;
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                connect[i][j] = min(connect[i][j], connect[i][k] + connect[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (connect[i][j] != INF) cnt++;
            if (connect[j][i] != INF) cnt++;
        }
        if (cnt == n - 1) ans++;
    }
    printf("%d\n", ans);
}