#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 1000;
const int INF = 1e9;
int N, M, A, B, K, G;
vector<p> adj[SIZE];
map<p, p> edge;
int dijk(int start, int end){
    priority_queue<p, vector<p>, greater<p>> pq;
    int dist[SIZE]{};
    bool visited[SIZE]{};
    fill(dist, dist + SIZE, INF);
    dist[start] = K;
    pq.push({K, start});
    while(!pq.empty()){
        int curr;
        do {
            curr = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[curr]);
        if (visited[curr]) break;
        visited[curr] = true;
        for (auto pNext : adj[curr]){
            int next = pNext.first, w = pNext.second;
            int a = min(curr,next), b = max(curr,next);
            int L = edge[{a,b}].first, R = edge[{a,b}].second;
            int t = 0;
            if (L <= dist[curr] && dist[curr] < R){
                t = R - dist[curr];
            }
            if (dist[next] > dist[curr] + w + t){
                dist[next] = dist[curr] + w + t;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[end];
}
int main(){
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &A, &B, &K, &G);
    vector<int> king;
    for (int i = 0; i < G; i++){
        int in;
        scanf("%d", &in);
        king.push_back(in-1);
    }
    for (int i = 0; i < M; i++){
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        u--, v--;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    int t = 0;
    for (int i = 0; i < G - 1; i++){
        for (auto pNext : adj[king[i]]){
            int next = pNext.first;
            int w = pNext.second;
            if (next != king[i+1]) continue;
            int s = min(king[i], next);
            int e = max(king[i], next);
            edge[{s,e}] = {t, t + w};
            t += w;
        }
    }
    int ret = dijk(A-1, B-1);
    printf("%d\n", ret - K);
}