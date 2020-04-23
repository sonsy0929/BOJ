#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, -1, 0, 1};
int isWall[100][100][4], uf[10000], N, K, R;
p cow[100];
map<p, int> mp;
void init() {
    fastio;
    memset(uf, -1, sizeof(uf));
    for (int d = 0; d < 4; d++) {
        mp[{roff[d], coff[d]}] = d;
    }
}
bool isIn(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
}
int find(int n) {
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    uf[u] = v;
}
int main() {
    init();
    cin >> N >> K >> R;
    int r, c, nr, nc;
    p d, nd;
    for (int i = 0; i < R; i++) {
        cin >> r >> c >> nr >> nc;
        r--, c--, nr--, nc--;
        d = {nr - r, nc - c};
        nd = {r - nr, c - nc};
        isWall[r][c][mp[d]] = isWall[nr][nc][mp[nd]] = 1;
    }
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        r--, c--;
        cow[i] = {r, c};
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d = 0; d < 4; d++) {
                int ni = i + roff[d], nj = j + coff[d];
                if (!isIn(ni, nj) || isWall[i][j][d]) continue;
                merge(i * N + j, ni * N + nj);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        auto [r, c] = cow[i];
        for (int j = i + 1; j < K; j++) {
            auto [nr, nc] = cow[j];
            ans += find(r * N + c) != find(nr * N + nc);
        }
    }
    cout << ans;
}