#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int MAXSIZE = 100'000;
constexpr int K = 18;
vector<int> adj[MAXSIZE];
int N, Q, p[MAXSIZE][K], depth[MAXSIZE];
void dfs(int curr){
    for (int next : adj[curr]){
        if (depth[next] != -1) continue;
        depth[next] = depth[curr] + 1;
        p[next][0] = curr;
        dfs(next);
    }
}
int main(){
    scanf("%d", &N);
    int u, v;
    for (int i = 0; i < N-1; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    memset(p, -1, sizeof(p));
    depth[0] = 0;
    dfs(0);
    for (int j = 1; j < K; j++){
        for (int i = 0; i < N; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; diff; j++){
            if (diff % 2) u = p[u][j];
            diff /= 2;
        }
        if (u != v){
            for (int j = K - 1; j >= 0; j--){
                if (p[u][j] != -1 && p[u][j] != p[v][j]){
                    u = p[u][j];
                    v = p[v][j];
                }
            }
            u = p[u][0];
        }
        printf("%d\n", u + 1);
    }
}