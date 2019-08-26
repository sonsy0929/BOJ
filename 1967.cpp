#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 10000;
vector<p> adj[SIZE];
int dist[SIZE], dist2[SIZE], far[SIZE];
bool visited[SIZE];
int dist_dfs(int curr){
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
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dist_dfs(0);
    int ans = 0;
    for (int i = 0; i < N; i++){
        ans = max(ans, dist[i] + dist2[i]);
    }
    printf("%d\n", ans);
}