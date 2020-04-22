/*
idea : �� component���� �ϳ��� �������� �����, MST�� �������.

component���� �ϳ��� �������� ���鶧 union-find�� ���
�� �������� �Ÿ��� ���� ��, ������ �Ÿ��� �����ϰ� �ּ� ���� ���� �Ÿ��� >= 2

-(��) : r���� �����ϹǷ� ���� ������ c���� �־��־� ���̸� �����ش�.
|(��) : c���� �����ϹǷ� ���� ������ r���� �־��־� ���̸� �����ش�.

���� kruskal algorithm�� ���� MST�� �������ش�.
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