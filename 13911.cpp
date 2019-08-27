#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int INF = 1e9;
const int SIZE = 10'010;
vector<p> adj[SIZE];
bool notTown[SIZE];
vector<int> dijk(int start){
    priority_queue<p, vector<p>, greater<p>> pq;
    bool visited[SIZE]{};
    vector<int> dist(SIZE, INF);
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()){
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
    return dist;
}
int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int M, S, x, y;
    scanf("%d %d", &M, &x);
    vector<int> mac, star;
    for (int i = 0; i < M; i++){
        int in;
        scanf("%d", &in);
        mac.push_back(in);
        notTown[in] = true;
    }
    const int mS = 0, sS = 10'001;
    for (int curr : mac) adj[mS].push_back({curr, 0});
    scanf("%d %d", &S, &y);
    for (int i = 0; i < S; i++){
        int in;
        scanf("%d", &in);
        star.push_back(in);
        notTown[in] = true;
    }
    for (int curr : star) adj[sS].push_back({curr, 0});
    vector<int> macDist, starDist;
    macDist = dijk(mS);
    starDist = dijk(sS);
    int ans = INF;
    for (int i = 1; i <= V; i++){
        if (macDist[i] > x || starDist[i] > y || notTown[i]) continue;
        ans = min(ans, macDist[i] + starDist[i]);
    }
    printf("%d\n", ans != INF ? ans : -1);
}