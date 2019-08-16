#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
using p = pair<int, int>;
vector<p> adj[500];
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
    }
    int dist[500];
    memset(dist, INF, sizeof(dist));
    dist[0] = 0;
    bool minusCycle = false;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (dist[j] == INF) continue;
            for (auto pNext : adj[j]){
                int next = pNext.first;
                int cost = pNext.second;
                if (dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;
                    if (i == N - 1) minusCycle = true;
                }
            }
        }
    }
    if (minusCycle) puts("-1");
    else {
        for (int i = 1; i < N; i++){
            printf("%d\n", dist[i] != INF ? dist[i] : -1);
        }
    }
}