#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 100'000;
int dist[SIZE], dist2[SIZE], far[SIZE];
bool visited[SIZE];
vector<int> adj[SIZE];
void dist_dfs(int curr){
    visited[curr] = true;
    for (int next : adj[curr]){
        if (!visited[next]){
            dist_dfs(next);
            if (dist[next] + 1 > dist[curr]){
                dist2[curr] = dist[curr];
                dist[curr] = dist[next] + 1;
            }
            else if (dist[next] + 1 > dist2[curr]){
                dist2[curr] = dist[next] + 1;
            }
        }
    }
}
void far_dfs(int curr, int pFar){
    visited[curr] = true;
    far[curr] = max(dist[curr], pFar);
    for (int next : adj[curr]){
        if (!visited[next]){
            if (dist[curr] == dist[next] + 1) 
                far_dfs(next, max(pFar + 1, dist2[curr] + 1));
            else
                far_dfs(next, max(pFar + 1, dist[curr] + 1));
        }
    }
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist_dfs(0);
    fill(visited, visited + SIZE, false);
    far_dfs(0, 0);
    int ans = 1e9;
    for (int i = 0; i < N; i++) ans = min(ans, far[i]);
    printf("%d\n", ans);
}