#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int K = 14;
const int SIZE = 10'000;
vector<int> adj[SIZE];
int depth[SIZE], pa[SIZE][K];
void init(){
    for (int i = 0; i < SIZE; i++) adj[i].clear();
}
void dfs(int curr){
    for (int next : adj[curr]){
        if (depth[next] == -1){
            pa[next][0] = curr;
            depth[next] = depth[curr] + 1;
            dfs(next);
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        int N, u, v, in[SIZE]{};
        scanf("%d", &N);
        for (int i = 0; i < N - 1; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            adj[u].push_back(v);
            in[v]++;
        }
        int root = 0;
        for (int i = 0; i < N; i++){
            if (!in[i]) {
                root = i;
                break;
            }
        }
        memset(pa, -1, sizeof(pa));
        memset(depth, -1, sizeof(depth));
        depth[root] = 0;
        dfs(root);
        for (int j = 1; j < K; j++){
            for (int i = 0; i < N; i++){
                if (pa[i][j-1] == -1) continue;
                pa[i][j] = pa[pa[i][j-1]][j-1];
            }
        }
        scanf("%d %d", &u, &v);
        u--, v--;
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
        printf("%d\n", u + 1);
    }
}