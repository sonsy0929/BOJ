/*
�ð����⵵ : O(N^3)

(0, 0)�� �׻� ������ ���� �̿��ؼ�, ġ���� �ܺο��� ����� �´�� �κ��� ���� ó���� �� �ִ�.
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