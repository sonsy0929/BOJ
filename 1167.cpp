#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 100'000;
vector<p> adj[SIZE];
int dist[SIZE], dist2[SIZE];
bool visited[SIZE];
void dist_dfs(int curr){
    visited[curr] = true;
    for (auto pNext : adj[curr]){
        int next = pNext.first;
        int w = pNext.second;
        if (visited[next]) continue;
        dist_dfs(next);
        if (dist[next] + w > dist[curr]){
            dist2[curr] = dist[curr];
            dist[curr] = dist[next] + w;
        }
        else if (dist[next] + w > dist2[curr]){
            dist2[curr] = dist[next] + w;
        }
    }
}
int main(){
    int V;
    scanf("%d", &V);
    for (int i = 0; i < V; i++){
        int u;
        scanf("%d", &u);
        u--;
        while (1){
            int v, w;
            scanf("%d", &v);
            if (v == -1) break;
            scanf("%d", &w);
            v--;
            adj[u].push_back({v,w});
        }
    }
    dist_dfs(0);
    int ans = 0;
    for (int i = 0; i < V; i++){
        ans = max(ans, dist[i] + dist2[i]);
    }
    printf("%d\n", ans);
}