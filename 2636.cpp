/*
시간복잡도 : O(N^3)

(0, 0)이 항상 공기인 점을 이용해서, 치즈의 외부에서 공기와 맞닿는 부분을 쉽게 처리할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int R, C, remain, sz, cheese[110][110];
bool v[110][110];
bool isIn(int r, int c) {
    return r >= 0 && c >= 0 && r < R && c < C;
}
void f(int r, int c) {
    v[r][c] = true;
    if (cheese[r][c]) {
        remain--; sz++;
        cheese[r][c] = 0;
        return;
    }
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (!isIn(nr, nc) || v[nr][nc]) continue;
        f(nr, nc);
    }
}
int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &cheese[i][j]);
            remain += cheese[i][j];
        }
    }
    int t = 0;
    for (; remain; t++) {
        memset(v, false, sizeof(v));
        sz = 0;
        f(0, 0);
    }
    printf("%d\n%d", t, sz);
}