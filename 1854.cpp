#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
using p = pair<int,int>;
const int INF = 0x3f3f3f3f;
vector<p> adj[1000];
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        adj[a].push_back({b, c});
    }
    priority_queue<p, vector<p>, greater<p>> pq;
    priority_queue<int> dist[1000];
    pq.push({0, 0});
    dist[0].push(0);
    while (!pq.empty()){
        int curr, val;
        tie(val, curr) = pq.top();
        pq.pop();
        for (auto pNext : adj[curr]){
            int next = pNext.first;
            int cost = pNext.second;
            int sumDist = val + cost;
            if (dist[next].size() < k) dist[next].push(sumDist);
            else if (dist[next].top() > sumDist){
                dist[next].pop();
                dist[next].push(sumDist);
            }
            else continue;
            pq.push({sumDist, next});
        }
    }
    for (int i = 0; i < n; i++){
        if (dist[i].size() < k) puts("-1");
        else printf("%d\n", dist[i].top());
    }
}