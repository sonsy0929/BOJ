#include <bits/stdc++.h>
using namespace std;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
vector<int> perm(25, 0);
int maze[5][5], cnt;
bool visited[5][5];
bool inPos(int r, int c) {
    if (r < 0 || c < 0 || r >= 5 || c >= 5) return false;
    return true;
}
int dfs(int r, int c) {
    int ret = maze[r][c];
    visited[r][c] = true;
    cnt++;
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (!inPos(nr, nc) || visited[nr][nc]) continue;
        if (perm[nr * 5 + nc]) ret += dfs(nr, nc);
    }
    return ret;
}
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char c;
            scanf(" %c", &c);
            maze[i][j] = c == 'S';
        }
    }
    for (int i = 18; i < 25; i++) {
        perm[i] = 1;
    }
    int ans = 0;
    do {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        int nxt = max_element(perm.begin(), perm.end()) - perm.begin();
        if (dfs(nxt / 5, nxt % 5) >= 4 && cnt == 7) ans++;
    } while (next_permutation(perm.begin(), perm.end()));
    printf("%d\n", ans);
}