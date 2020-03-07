/*
�ð����⵵ : O(N^2 * 64_C_3)

�ϴ�, ���� N * N �������� ��Ʈ��ŷ�� ���� �� ĭ�� 3���� ���� �������鼭,
bfs �Լ��� ���� ���̷����� ���� ĭ�� ������ �����־���.
���� S�� �ǹ̴� ���� ������ ������ ĭ�� �����̴�.
����, S - (���̷����� ���� ĭ�� ����) = ���� �����̹Ƿ�
�̸� ���� ���� ���� ũ���� �ִ밪�� �����־���.
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