#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;
using p = pair<int, int>;
const int INF = 0x3f3f3f3f;
vector<p> adj[20000];
int dist[20000];
bool visited[20000];
int main(){
    int v, e, start;
    scanf("%d %d", &v, &e);
    scanf("%d", &start);
    start--;
    for (int i = 0; i < e; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
    }
    priority_queue<p, vector<p>, greater<p>> pq;
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        int curr;
        do {
            curr = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[curr]);
        if (visited[curr]) break;
        visited[curr] = true;
        for (auto pNext : adj[curr]){
            int next = pNext.first, w = pNext.second;
            if (dist[next] > dist[curr] + w){
                dist[next] = dist[curr] + w;
                pq.push({dist[next], next});
            }
        }
    }
    for (int i = 0; i < v; i++){
        if (dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }
}