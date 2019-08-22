#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using ll = long long;
using tup = tuple<ll,int,int>;
const int SIZE = 50'000;
const ll INF = 1e18;
int n, m, f, s, t;
vector<p> adj[SIZE];
vector<int> flight[SIZE];
int main(){
    scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
    int u, v, w;
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < f; i++){
        scanf("%d %d", &u, &v);
        flight[u].push_back(v);
    }
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    bool visited[SIZE][2]{};
    ll dist[SIZE][2];
    for (int i = 0; i < SIZE; i++){
        fill(dist[i], dist[i] + 2, INF);
    }
    dist[s][1] = 0;
    pq.push({0, s, 1});
    while(!pq.empty()){
        int curr, d, possible;
        do {
            tie(d, curr, possible) = pq.top();
            pq.pop();
        } while(!pq.empty() && visited[curr][possible]);
        if (visited[curr][possible]) break;
        visited[curr][possible] = true;
        if (possible){
            for (int next : flight[curr]){
                if (dist[next][possible - 1] > dist[curr][possible]){
                    dist[next][possible - 1] = dist[curr][possible];
                    pq.push({dist[next][possible - 1], next, 0});
                }
            }
        }
        for (auto pNext : adj[curr]){
            int next = pNext.first;
            int w = pNext.second;
            if (dist[next][possible] > dist[curr][possible] + w){
                dist[next][possible] = dist[curr][possible] + w;
                pq.push({dist[next][possible], next, possible});
            }
        }
    }
    ll ans = min(dist[t][0], dist[t][1]);
    printf("%lld\n", ans);
}