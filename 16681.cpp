#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
const ll INF = 1e18;
const int SIZE = 100'000;
int N, M, D, E;
int tall[SIZE];
vector<p> adj[SIZE];
void getDist(int start, ll dist[SIZE]){
    priority_queue<p, vector<p>, greater<p>> pq;
    bool visited[SIZE]{};
    pq.push({-INF, start});
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
            if (tall[curr] >= tall[next]) continue;
            if (dist[next] > dist[curr] + w){
                dist[next] = dist[curr] + w;
                pq.push({dist[next], next});
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d", &N, &M, &D, &E);
    for (int i = 0; i < N; i++) scanf("%d", tall + i);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    ll h2D[SIZE], k2D[SIZE];
    fill(h2D, h2D + SIZE, INF);
    fill(k2D, k2D + SIZE, INF);
    getDist(0, h2D);
    getDist(N - 1, k2D);
    ll ans = -INF;
    for (int i = 0; i < N; i++){
        ll dist = h2D[i] + k2D[i];
        if (dist >= INF) continue;
        ll hE = tall[i] * E;
        ans = max(ans, hE - dist * D);
    }
    if (ans != -INF) printf("%lld\n", ans);
    else puts("Impossible");
}