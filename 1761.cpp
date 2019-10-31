#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
constexpr int K = 17;
constexpr int MAXSIZE = 40'000;
int N, M, depth[MAXSIZE], parent[MAXSIZE][K], dist[MAXSIZE];
vector<p> adj[MAXSIZE];
void dfs(int curr){
    for (auto pNext : adj[curr]){
        int next = pNext.first;
        int w = pNext.second;
        if (depth[next] != -1) continue;
        depth[next] = depth[curr] + 1;
        parent[next][0] = curr;
        dist[next] = dist[curr] + w;
        dfs(next);
    }
}
int main(){
    int u, v, w;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++){
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));
    depth[0] = 0;
    dist[0] = 0;
    dfs(0);
    for (int j = 1; j < K; j++){
        for (int i = 0; i < N; i++){
            if (parent[i][j-1] == -1) continue;
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    scanf("%d", &M);
    int a, b;   
    for (int q = 0; q < M; q++){
        scanf("%d %d", &u, &v);
        u--, v--;
        a = u, b = v;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; diff; i++){
            if (diff % 2) u = parent[u][i];
            diff /= 2; 
        }
        if (u != v){
            for (int i = K - 1; i >= 0; i--){
                if (parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            u = parent[u][0];
        }
        int distAtoU = dist[a] - dist[u];
        int distBtoU = dist[b] - dist[u];
        printf("%d\n", distAtoU + distBtoU);
    }
}