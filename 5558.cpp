#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
char maze[1000][1000];
int H, W, N;
bool isIn(int r, int c) {
    return r >= 0 && c >= 0 && r < H && c < W;
}
int bfs(p start, p end) {
    queue<p> q;
    bool visited[1000][1000]{};
    q.push(start);
    visited[start.first][start.second] = true;
    for (int d = 0; !q.empty(); d++) {
        int qSize = q.size();
        for (int s = 0; s < qSize; s++) {
            auto [r, c] = q.front();
            q.pop();
            if (p(r, c) == end) return d;
            for (int d = 0; d < 4; d++) {
                int nr = r + roff[d], nc = c + coff[d];
                if (!isIn(nr, nc) || visited[nr][nc] || maze[nr][nc] == 'X') continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    return 1e9;
}
int main() {
    scanf("%d %d %d", &H, &W, &N);
    p curr, next;
    vector<p> factory;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'S') curr = {i, j};
            if (maze[i][j] >= '1' && maze[i][j] <= '9') {
                factory.push_back({maze[i][j] - '0', i * W + j});
            }
        }
    }
    sort(factory.begin(), factory.end());
    int ans = 0;
    for (auto [w, loc] : factory) {
        next = {loc / W, loc % W};
        ans += bfs(curr, next);
        curr = next;
    }
    printf("%d", ans);
}