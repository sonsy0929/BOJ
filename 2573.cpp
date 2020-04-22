#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int N, M, ice[310][310];
bool visited[310][310];
void melting() {
    vector<p> sea;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!ice[i][j]) sea.push_back({i, j});
        }
    }
    int cnt[310][310]{};
    for (auto [r, c] : sea) {
        for (int d = 0; d < 4; d++) {
            int nr = r + roff[d], nc = c + coff[d];
            cnt[nr][nc]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ice[i][j] = max(0, ice[i][j] - cnt[i][j]);
        }
    }
}
bool isIn(int r, int c) {
    return r > 0 && c > 0 && r <= N && c <= M;
}
void dfs(int r, int c) {
    visited[r][c] = true;
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (!isIn(nr, nc) || visited[nr][nc]) continue;
        if (ice[nr][nc]) dfs(nr, nc);
    }
}
bool allZero() {
    bool ret = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ret &= !ice[i][j];
        }
    }
    return ret;
}
int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> ice[i][j];
        }
    }
    int ans = 0, component = 0;
    for (; !allZero() && component < 2; ans++) {
        melting();
        memset(visited, false, sizeof(visited));
        component = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (ice[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    component++;
                }
            }
        }
    }
    if (component >= 2) cout << ans;
    else cout << "0";
}