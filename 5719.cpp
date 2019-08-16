#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;
using p = pair<int,int>;
const int INF = 0x3f3f3f3f;
const int SIZE = 500;
vector<p> out[SIZE];
vector<p> in[SIZE];
int dist[SIZE], n, m;
bool isMinEdge[SIZE][SIZE];
void getMinDist(int start, int dest){
    memset(dist, INF, sizeof(dist));
    bool visited[SIZE]{};
    priority_queue<p, vector<p>, greater<p>> pq;
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
        for (auto eNext : out[curr]){
            int next = eNext.first, w = eNext.second;
            bool iMe = isMinEdge[next][curr];
            if (iMe) continue;
            if (dist[next] > dist[curr] + w){
                dist[next] = dist[curr] + w;
                pq.push({dist[next], next});
            }
        }
    }
}
void bfs(int start, int dest){
    queue<p> q;
    q.push({start, dist[start]});
    while (!q.empty()){
        int curr = q.front().first;
        int d = q.front().second;
        q.pop();
        for (auto &eNext : in[curr]){
            int next = eNext.first;
            int w = eNext.second;
            bool &iMe = isMinEdge[curr][next];
            if (d == dist[next] + w) {
                iMe = true;
                q.push({next, dist[next]});
            }
        }
    }
}
void init(){
    for (int i = 0; i < SIZE; i++) {
        out[i].clear();
        in[i].clear();
    }
    memset(isMinEdge, false, sizeof(isMinEdge));
}
int main(){
    while (scanf("%d %d", &n, &m)){
        if (n == 0 && m == 0) break;
        init();
        int S, D;
        scanf("%d %d", &S, &D);
        for (int i = 0; i < m; i++){
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            in[v].push_back({u, p});
            out[u].push_back({v, p});
        }
        getMinDist(S, D);
        bfs(D, S);
        getMinDist(S, D);
        printf("%d\n", dist[D] != INF ? dist[D] : -1);
    }
}