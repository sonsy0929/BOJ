#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int K = 12;
const int SIZE = 2000;
int N, depth[SIZE], pa[SIZE][K], idx[SIZE * 2];
char cmd[SIZE * 2 + 1];
int main(){
    scanf("%d %s", &N, cmd);
    int curr = 0, next = 1;
    memset(pa, -1, sizeof(pa));
    depth[0] = 0;
    for (int i = 1; i < 2 * N; i++){
        if (cmd[i] == '0'){
            depth[next] = depth[curr] + 1;
            pa[next][0] = curr;
            idx[i] = next;
            curr = next++;
        }
        else {
            idx[i] = curr;
            curr = pa[curr][0];
        }
    }
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    u = idx[u], v = idx[v];
    for (int j = 1; j < K; j++){    
        for (int i = 0; i < N; i++){
            if (pa[i][j-1] == -1) continue;
            pa[i][j] = pa[pa[i][j-1]][j-1];
        }
    }
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++){
        if (diff % 2) u = pa[u][i];
        diff /= 2;
    }
    if (u != v){
        for (int i = K - 1; i >= 0; i--){
            if (pa[u][i] == -1) continue;
            if (pa[u][i] != pa[v][i]){
                u = pa[u][i];
                v = pa[v][i];
            }
        }
        u = pa[u][0];
    }
    int o, c;
    for (int i = 0; i < 2 * N; i++){
        if (cmd[i] == '0' && idx[i] == u) o = i + 1;
        if (cmd[i] == '1' && idx[i] == u) c = i + 1;
    }
    printf("%d %d\n", o, c);
}