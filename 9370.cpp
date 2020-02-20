/*
시간복잡도 : O(MlogN)

목적지 후보군 중 g - h를 거치는 최단경로 목적지를 찾으면 된다.
s -> g -> h -> d 혹은 s -> h -> g -> d 이 두 가지 경우에 대해서
목적지에 최단경로로 도달하는지 확인만 하면 된다. 
*/
#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int SIZE = 2010;
const int INF = 1e9;
int TC, N, M, T, S, G, H;
vector<p> adj[SIZE];
vector<int> dijk(int start) {
    vector<int> dist(SIZE, INF);
    priority_queue<p, vector<p>, greater<p>> pq;
    bool visited[SIZE]{};
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int curr;
        do {
            curr = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visited[curr]);
        if (visited[curr]) break;
        visited[curr] = true;
        for (auto [next, w] : adj[curr]) {
            if (dist[next] > dist[curr] + w) {
                dist[next] = dist[curr] + w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}
void init() {
    for (int i = 0; i < SIZE; i++) adj[i].clear();
}
int main() {
    scanf("%d", &TC);
    while (TC--) {
        init();
        scanf("%d %d %d", &N, &M, &T);
        scanf("%d %d %d", &S, &G, &H);
        for (int i = 0; i < M; i++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        vector<int> dest(T, 0);
        for (int i = 0; i < T; i++) {
            scanf("%d", &dest[i]);
        }
        vector<int> dist_S, dist_G, dist_H;
        dist_S = dijk(S);
        dist_G = dijk(G);
        dist_H = dijk(H);
        vector<int> res;
        for (int curr : dest) {
            int SGH = dist_S[G] + dist_G[H] + dist_H[curr];
            int SHG = dist_S[H] + dist_H[G] + dist_G[curr];
            if (SGH == dist_S[curr] || SHG == dist_S[curr]) res.push_back(curr);
        }
        sort(res.begin(), res.end());
        for (int ans : res) printf("%d ", ans);
        puts("");
    }
}