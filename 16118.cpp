#include <bits/stdc++.h>
using namespace std;
using p = pair<int,int>;
using tup = tuple<int,int,int>;
constexpr int INF = 2e9;
int N, M, fox[4010][2], wolf[4010][2];
vector<p> graph[4010];
void dijk(int start, bool isWolf, int dist[][2]){
    for (int i = 0; i < 4010; i++) fill(dist[i], dist[i] + 2, INF);
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    bool visited[4010][2]{};
    pq.push({0, 1, true});
    dist[1][1] = 0;
    while(!pq.empty()){
        int d, c, s;
        do {
            tie(d, c, s) = pq.top();
            pq.pop();
        } while(!pq.empty() && visited[c][s]);
        if (visited[c][s]) break;
        visited[c][s] = true;
        for (auto pNext : graph[c]){
            int next, w;
            tie(next, w) = pNext;
            if (isWolf){
                if (s) w /= 2;
                else w *= 2;
            }
             if (dist[next][!s] > dist[c][s] + w){
                dist[next][!s] = dist[c][s] + w;
                pq.push({dist[next][!s], next, !s});
            }
        }
    }
}
int main(){
    scanf("%d %d", &N,&M);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u,&v,&w);
        graph[u].push_back({v, w*2});
        graph[v].push_back({u, w*2});
    }
    dijk(1, false, fox);
    dijk(1, true, wolf);
    int ans = 0;
    for (int i = 1; i <= N; i++){
        if (min(fox[i][0], fox[i][1]) < min(wolf[i][0],wolf[i][1])) ans++;
    }
    printf("%d\n", ans);
}