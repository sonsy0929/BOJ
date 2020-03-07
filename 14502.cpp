/*
시간복잡도 : O(N^2 * 64_C_3)

일단, 먼저 N * N 지도에서 백트래킹을 통해 빈 칸에 3개의 벽을 세워보면서,
bfs 함수를 통해 바이러스가 퍼진 칸의 개수를 구해주었다.
변수 S의 의미는 벽인 지점을 제외한 칸의 개수이다.
따라서, S - (바이러스가 퍼진 칸의 개수) = 안전 영역이므로
이를 통해 안전 영역 크기의 최대값을 구해주었다.
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, M, maze[8][8], ans, S;
vector<p> wall, virus;
bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}
int bfs() {
    int newMaze[8][8]{};
    memcpy(newMaze, maze, sizeof(maze));
    for (auto [r, c] : wall) {
        newMaze[r][c] = 1;
    }
    queue<p> q;
    bool visited[8][8]{};
    for (auto pCurr : virus) {
        q.push(pCurr);
    }
    int ret = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        ret++;
        for (int d = 0; d < 4; d++) {
            int nr = r + roff[d];
            int nc = c + coff[d];
            if (!isIn(nr, nc) || visited[nr][nc] || newMaze[nr][nc]) continue;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
    return ret;
}
void comb(int r, int c, int cnt) {
    if (cnt == 3) {
        ans = max(ans, S - bfs());
        return;
    }
    for (int i = r; i < N; i++) {
        for (int j = (i == r ? c : 0); j < M; j++) {
            if (maze[i][j]) continue;
            wall.push_back({i, j});
            comb(i, j + 1, cnt + 1);
            wall.pop_back();
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    S = N * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &maze[i][j]);
            if (maze[i][j] == 1) S--;
            if (maze[i][j] == 2) virus.push_back({i, j});
        }
    }
    S -= 3;
    comb(0, 0, 0);
    printf("%d\n", ans);
}