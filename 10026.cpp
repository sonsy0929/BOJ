#include <bits/stdc++.h>
using namespace std;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N;
char rgb[100][100], rb[100][100];
bool visited[100][100];
bool isIn(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}
void dfs(int r, int c, char color, char maze[][100]) {
    visited[r][c] = true;
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d];
        int nc = c + coff[d];
        if (!isIn(nr, nc) || visited[nr][nc]) continue;
        if (maze[nr][nc] == color) {
            dfs(nr, nc, color, maze);
        }
    }
}
int rgbCnt() {
    memset(visited, false, sizeof(visited));
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, rgb[i][j], rgb);
                ret++;
            }
        }
    }
    return ret;
}
int rbCnt() {
    memset(visited, false, sizeof(visited));
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, rb[i][j], rb);
                ret++;
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &rgb[i][j]);
            if (rgb[i][j] != 'B') rb[i][j] = 'R';
        }
    }
    printf("%d %d", rgbCnt(), rbCnt());
}