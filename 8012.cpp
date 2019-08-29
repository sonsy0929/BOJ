#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 30'000;
const int K = 16;
vector<int> adj[SIZE];
int depth[SIZE], pa[SIZE][K];
void dfs(int curr){
    for (int next : adj[curr]){
        if (depth[next] == -1){
            depth[next] = depth[curr] + 1;
            pa[next][0] = curr;
            dfs(next);
        }
    }
}
int main(){
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    memset(pa, -1, sizeof(pa));
    depth[0] = 0;
    dfs(0);
    for (int j = 1; j < K; j++){
        for (int i = 1; i < N; i++){
            if (pa[i][j-1] == -1) continue;
            pa[i][j] = pa[pa[i][j-1]][j-1];
        }
    }
    int u = 0, v, ans = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        scanf("%d", &v);
        v--;
        int tu = u, tv = v;
        if (depth[tu] < depth[tv]) swap(tu, tv);
        int diff = depth[tu] - depth[tv];
        for (int j = 0; diff; j++){
            if (diff % 2) tu = pa[tu][j];
            diff /= 2;
        }
        if (tu != tv){
            for (int j = K - 1; j >= 0; j--){
                if (pa[tu][j] == -1) continue;
                if (pa[tu][j] != pa[tv][j]){
                    tu = pa[tu][j];
                    tv = pa[tv][j];
                }
            }
            tu = pa[tu][0];
        }
        int dist = depth[u] - depth[tu] + depth[v] - depth[tu];
        ans += dist;
        u = v;
    }
    printf("%d\n", ans);
}