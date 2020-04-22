#include <bits/stdc++.h>
using namespace std;
const int roff[] = {0, -1, 0, 1};
const int coff[] = {-1, 0, 1, 0};
int N, M, uf[2500], maze[50][50];
int find(int n) {
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    uf[u] += uf[v];
    uf[v] = u;
}
bool isIn(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < M;
}
int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    memset(uf, -1, sizeof(uf));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bitset<4> wall(maze[i][j]);
            for (int d = 0; d < 4; d++) {
                int ni = i + roff[d], nj = j + coff[d];
                if (!isIn(ni, nj) || wall[d]) continue;
                merge(i * M + j, ni * M + nj);
            }
        }
    }
    int ans[3]{};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (uf[i * M + j] < 0) {
                ans[0]++;
                ans[1] = max(ans[1], -uf[i * M + j]);
            }
            for (int d = 0; d < 4; d++) {
                int ni = i + roff[d], nj = j + coff[d];
                if (!isIn(ni, nj)) continue;
                int u = find(i * M + j), v = find(ni * M + nj);
                if (u != v) ans[2] = max(ans[2], -uf[u] - uf[v]);
            }
        }
    }
    for (int i = 0; i < 3; i++) printf("%d\n", ans[i]);
}