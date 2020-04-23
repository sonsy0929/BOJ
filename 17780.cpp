#include <bits/stdc++.h>
using namespace std;
struct Chess {
    int r, c, d;
};
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int N, K, maze[15][15];
bool isIn(int r, int c) {
    return r >= 1 && r <= N && c >= 1 && c <= N;
}
int getDir(int d) {
    int D[5] = {-1, 1, 3, 0, 2};
    return D[d];
}
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    vector<Chess> chesses;
    vector<int> board[15][15];
    for (int i = 0, r, c, d; i < K; i++) {
        scanf("%d %d %d", &r, &c, &d);
        chesses.push_back({r, c, getDir(d)});
        board[r][c].push_back(i);
    }
    for (int t = 1;; t++) {
        for (int i = 0; i < K; i++) {
            auto [r, c, d] = chesses[i];
            int f = board[r][c].front();
            if (f != i) continue;
            auto [fr, fc, fd] = chesses[f];
            int nr = fr + roff[fd], nc = fc + coff[fd];
            if (!isIn(nr, nc) || maze[nr][nc] == 2) {
                fd = (fd + 2) % 4;
                nr = fr + roff[fd], nc = fc + coff[fd];
                chesses[f].d = fd;
                if (maze[nr][nc] == 2 || !isIn(nr, nc)) {
                    nr = fr, nc = fc;
                    continue;
                }
            }
            if (maze[nr][nc] == 1) reverse(board[fr][fc].begin(), board[fr][fc].end());
            for (int e : board[fr][fc]) {
                chesses[e].r = nr;
                chesses[e].c = nc;
            }
            for (int e : board[fr][fc]) board[nr][nc].push_back(e);
            board[fr][fc].clear();
        }
        if (t > 1000) return !printf("-1");
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][j].size() >= 4) {
                    return !printf("%d", t);
                }
            }
        }
    }
}