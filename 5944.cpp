#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
using p = pair<int,int>;
const int SIZE = 100'000;
vector<p> adj[SIZE];
const int INF = 1e9;
int getDist(int start, int dest){
    int dist[SIZE]{};
    bool visited[SIZE]{};
    priority_queue<p, vector<p>, greater<p>> pq;
    fill(dist, dist + SIZE, INF);
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
    int C, P, PB, PA1, PA2;
    scanf("%d %d %d %d %d", &C, &P, &PB, &PA1, &PA2);
    for (int i = 0; i < C; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    PB--, PA1--, PA2--;
    printf("%d\n", min(getDist(PB, PA1) + getDist(PA1, PA2), getDist(PB, PA2) + getDist(PA2, PA1)));
}