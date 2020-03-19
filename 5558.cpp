/*
시간복잡도 : O(W * H)

구하고자 하는 것은 쥐가 모든 치즈를 먹고 끝내는 데 걸리는 최소시간이다.
이 때, 쥐가 치즈를 먹지 못하는 경우는 
입력에서 주어지지 않는다고 해서, 따로 고려할 필요가 없다.

쥐는 상하좌우로 움직이는데 '1분'이라는 일정한 시간이 소요되므로,
0-1 bfs를 통해 최단거리를 구할 수 있다.
(만약, 가중치가 전부 다르다면 0-1 bfs로 구할 수 없고 다익스트라를 통해 구해야 한다.)
쥐는 자신의 체력보다 경도가 높은 치즈를 먹지 못하기 때문에,
쥐가 치즈의 경도 순으로 이동해야 하는 것은 자명한 사실이다.
즉, "시작점 -> 치즈 1 -> 치즈 2 -> ... -> 치즈 9" 순으로 
쥐가 최단거리로 움직인다면, 전체 또한 최단거리임을 알 수 있다.
*/

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