#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
using p = pair<int,int>;
constexpr int MAXSIZE = 10'000;
vector<p> adj[MAXSIZE];
vector<p> rev[MAXSIZE];
int dist[MAXSIZE];
int inD[MAXSIZE];
void topoSort(int start){
    queue<int> q;
    q.push(start);
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        for (auto &pNext : adj[curr]){
            int next = pNext.first;
            int w = pNext.second;
            dist[next] = max(dist[next], dist[curr] + w);
            if (--inD[next] == 0) q.push(next);
        }
    }
}
int bfs(int end){
    int ret = 0;
    queue<int> q;
    q.push(end);
    bool visited[MAXSIZE]{};
    visited[end] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (auto &pNext : rev[curr]){
            int prev = pNext.first;
            int w = pNext.second;
            if (dist[curr] == dist[prev] + w){
                ret++;
                if (visited[prev]) continue;
                visited[prev] = true;
                q.push(prev);
            }
        }
    }
    return ret;
}
int main(){
    int N, M, start, end;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        rev[v].push_back({u, w});
        inD[v]++;
    }
    scanf("%d %d", &start, &end);
    start--, end--;
    topoSort(start);
    printf("%lld\n%d", dist[end], bfs(end));
}