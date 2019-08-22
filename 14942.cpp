#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
using p = pair<int,int>;
const int K = 18;
const int SIZE = 100'000;
vector<p> adj[SIZE];
int N, E[SIZE], dist[SIZE], pa[SIZE][K];
void makeTree(int curr){
    for (auto pNext : adj[curr]){
        int next = pNext.first;
        int w = pNext.second;
        if (dist[next] == -1){
            dist[next] = dist[curr] + w;
            pa[next][0] = curr;
            makeTree(next);
        }
    }
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", E + i);
    for (int i = 0; i < N - 1; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--,v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(dist, -1, sizeof(dist));
    memset(pa, -1, sizeof(pa));
    dist[0] = 0;
    makeTree(0);
    for (int j = 1; j < K; j++){
        for (int i = 0; i < N; i++){
            if (pa[i][j-1] == -1) continue;
            pa[i][j] = pa[pa[i][j-1]][j-1];
        }
    }
    for (int i = 0; i < N; i++){
        int curr = i;
        for (int j = K - 1; j >= 0; j--){
            int parent = pa[curr][j];
            if (parent == -1) continue;
            if (dist[curr] - dist[parent] > E[i]) continue;
            E[i] -= dist[curr] - dist[parent];
            curr = pa[curr][j];
        }
        printf("%d\n", curr + 1);
    }
}