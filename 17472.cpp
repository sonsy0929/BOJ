/*
idea : 각 component들을 하나의 정점으로 만들어, MST를 사용하자.

component들을 하나의 정점으로 만들때 union-find를 사용
각 정점들의 거리를 구할 때, 직선인 거리만 가능하고 최소 정점 간의 거리가 >= 2

-(행) : r값은 일정하므로 섬인 지점의 c값만 넣어주어 차이를 구해준다.
|(열) : c값은 일정하므로 섬인 지점의 r값만 넣어주어 차이를 구해준다.

이후 kruskal algorithm을 통해 MST를 구축해준다.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 110, INF = 0x3f3f3f3f;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int N, M, maze[15][15], dist[SIZE][SIZE];
struct UF {
    int uf[SIZE];
    UF() {
        memset(uf, -1, sizeof(uf));
    }
    int find(int n) {
        if (uf[n] < 0) return n;
        return uf[n] = find(uf[n]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        uf[v] = u;
        return true;
    }
};
bool isIn(int r, int c) {
    return r >= 0 && r <= N && c >= 0 && c <= M;
}
void makeDist(UF& island, bool f) {
    for (int i = 0; i < (f ? N : M); i++) {
        vector<int> dv;
        for (int j = 0; j < (f ? M : N); j++) {
            if (f && maze[i][j]) dv.push_back(j);
            if (!f && maze[j][i]) dv.push_back(j);
        }
        for (int j = 1; j < dv.size(); j++) {
            int d = dv[j] - dv[j - 1] - 1;
            if (d >= 2) {
                int u = island.find(i * M + dv[j - 1]);
                int v = island.find(i * M + dv[j]);
                if (!f) {
                    u = island.find(dv[j - 1] * M + i);
                    v = island.find(dv[j] * M + i);
                }
                dist[u][v] = min(dist[u][v], d);
            }
        }
    }
}
int main() {
    UF island, uf;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j]) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + roff[d], nj = j + coff[d];
                    if (!isIn(ni, nj) || !maze[ni][nj]) continue;
                    island.merge(i * M + j, ni * M + nj);
                }
            }
        }
    }
    memset(dist, INF, sizeof(dist));
    makeDist(island, true);
    makeDist(island, false);
    using edge = tuple<int, int, int>;
    vector<edge> edges;
    int islandCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] && island.uf[i * M + j] < 0) islandCnt++;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (dist[i][j] != INF) edges.emplace_back(dist[i][j], i, j);
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0, cnt = 0;
    for (auto [d, u, v] : edges) {
        if (uf.merge(u, v)) {
            ans += d;
            if (++cnt == islandCnt - 1) break;
        }
    }
    if (cnt == islandCnt - 1) cout << ans;
    else cout << -1;
}