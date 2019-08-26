#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const int SIZE = 40'000;
const ll INF = 1e18;
vector<int> adj[SIZE];
int B, E, P, N, M;
void bfs(int start, int dist[SIZE]){
    queue<int> q;
    q.push(start);
    fill(dist, dist + SIZE, 1e9);
    dist[start] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]){
            if (dist[next] <= dist[curr] + 1) continue;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }
}
int main(){
    scanf("%d %d %d %d %d", &B, &E, &P, &N, &M);
    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dist[SIZE]{}, dist2[SIZE]{}, dist3[SIZE]{};
    bfs(0, dist);
    bfs(1, dist2);
    bfs(N-1, dist3);
    ll ans = INF;
    for (int i = 0; i < N; i++){
        ans = min(ans, 1LL * dist[i] * B + 1LL * dist2[i] * E + 1LL * dist3[i] * P);
    }
    printf("%lld\n", ans);
}