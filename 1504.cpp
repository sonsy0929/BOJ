#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int INF = 2e8;
const int SIZE = 800;
vector<p> adj[SIZE];
int getDist(int start, int dest){
    priority_queue<p, vector<p>, greater<p>> pq;
    int dist[SIZE];
    bool visited[SIZE]{};
    fill(dist, dist + SIZE, INF);
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int curr;
        do {
            curr = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[curr]);
        if (visited[curr]) break;
        visited[curr] = true;
        for (auto pNext : adj[curr]){
            int next = pNext.first;
            int w = pNext.second;
            if (dist[next] > dist[curr] + w){
                dist[next] = dist[curr] + w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[dest];
}
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int s, e;
    scanf("%d %d", &s, &e);
    s--, e--;
    int A = getDist(0, s) + getDist(s, e) + getDist(e, N-1);
    int B = getDist(0, e) + getDist(e, s) + getDist(s, N-1);
    int ans = min(A, B);
    printf("%d\n", ans < INF ? ans : -1);
}

