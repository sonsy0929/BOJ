#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 10'000;
const int INF = 1e9;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, d, c;
        scanf("%d %d %d", &n, &d, &c);
        vector<p> adj[SIZE];
        for (int i = 0; i < d; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--,v--;
            adj[v].push_back({u, w});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        int dist[SIZE]{};
        bool visited[SIZE]{};
        fill(dist, dist + SIZE, INF);
        dist[c-1] = 0;
        pq.push({0,c-1});
        while (!pq.empty()){
            int curr;
            do {
                curr = pq.top().second;
                pq.pop();
            } while(!pq.empty() && visited[curr]);
            if(visited[curr]) break;
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
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++){
            if (dist[i] == INF) continue;
            cnt++;
            ans = max(ans, dist[i]);
        }
        printf("%d %d\n", cnt, ans);
    }
}