#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
const int SIZE = 30;
const int INF = 1e9;
int w, h, g, e;
bool isPossible(int r, int c){
    if (r < 0 || c < 0 || r >= h || c >= w) return false;
    return true;
}
int main(){
    while (scanf("%d %d", &w, &h)){
        if (w == 0 && h == 0) break;
        scanf("%d", &g);
        vector<p> adj[SIZE * SIZE];
        int S = w * h;
        bool obstruct[SIZE][SIZE]{};
        bool hole[SIZE][SIZE]{};
        for (int i = 0; i < g; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            obstruct[y][x] = true;
        }
        scanf("%d", &e);
        for (int i = 0; i < e; i++){
            int x1, y1, x2, y2, t;
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
            adj[y1 * w + x1].push_back({y2 * w + x2, t});
            hole[y1][x1] = true;
        }
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                int u = i * w + j;
                if (hole[i][j] || obstruct[i][j]) continue;
                if (i == h - 1 && j == w - 1) continue;
                for (int d = 0; d < 4; d++){
                    int ni = i + roff[d];
                    int nj = j + coff[d];
                    if (!isPossible(ni, nj)) continue;
                    int v = ni * w + nj;
                    if (obstruct[ni][nj]) adj[u].push_back({v, INF});
                    else adj[u].push_back({v, 1});
                }
            }
        }
        int dist[S]{};
        fill(dist, dist + S, INF);
        dist[0] = 0;
        bool minusCycle = false;
        int dest = (h - 1) * w + (w - 1);
        int ans = INF;
        for (int i = 0; i < S; i++){
            for (int j = 0; j < S; j++){
                int r = j / w, c = j % w;
                if (obstruct[r][c] || dist[j] == INF) continue;
                for (auto pNext : adj[j]){
                    int next = pNext.first;
                    int cost = pNext.second;
                    if (dist[next] > dist[j] + cost){
                        dist[next] = dist[j] + cost;
                        if (i == S - 1) minusCycle = true;
                    }
                }
            }
        }
        if (minusCycle) puts("Never");
        else if (dist[dest] == INF) puts("Impossible");
        else printf("%d\n", dist[dest]);
    }
}