#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
const ll INF = 1e18;
const int SIZE = 100'000;
int N, M;
vector<p> adj[SIZE];
int main(){
    scanf("%d %d", &N, &M);
    bool visited[SIZE]{};
    for (int i = 0; i < N; i++){
        int in;
        scanf("%d", &in);
        if (i != N - 1) visited[i] = in;
    }
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    ll dist[SIZE];
    fill(dist, dist + SIZE, INF);
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, 0});
    dist[0] = 0;
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
    printf("%lld\n", dist[N - 1] != INF ? dist[N - 1] : -1);
}