#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 10'000;
int V, E, order, visited[SIZE], cut[SIZE];
vector<int> adj[SIZE];
int dfs(int curr, bool root){
    visited[curr] = ++order;
    int ret = visited[curr];
    int child = 0;
    for (int next : adj[curr]){
        if (!visited[next]){
            child++;
            int minVal = dfs(next, false);
            if (!root && minVal >= visited[curr]) cut[curr] = true;
            ret = min(ret, minVal);
        }
        else ret = min(ret, visited[next]);
    }
    if (root && child > 1) cut[curr] = true;
    return ret;
}
int main(){
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < V; i++){
        if (!visited[i]) dfs(i, true);
    }
    int ans = 0;
    for (int i = 0; i < V; i++){
        if (cut[i]) ans++;
    }
    printf("%d\n", ans);
    for (int i = 0; i < V; i++){
        if (cut[i]) printf("%d ", i + 1);
    }
}