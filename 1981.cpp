/*
�ð����⵵ : O(k * N^2)

�� ������ + dfs�� Ȱ���ؼ� Ǯ�̸� �Ͽ���.
(1, 1) -> (n, n)���� �̵��Ϸ� �� ��, �ִ밪 - �ּҰ��� ���̰� ���� �۾����� ��츦 ���ؾ� �Ѵ�.
�迭�� �Է¹����鼭 �ּҰ��� �ִ밪�� �����Ѵ�.
lo, hi �� ���� �����ͷ� ���� �����ϸ鼭 hi - lo�� �ּҰ��� ���ϸ� �ȴ�.
���� ���� lo, hi�� (1, 1) -> (n, n)�� ������ �����ϸ�, lo���� ����
�׷��� ������ hi���� ������Ű�鼭 hi - lo�� �ּҸ� �����ָ� �ȴ�.
����� �����δ� ����� �ѻ���� �ִٰ� �Ѵ�. �� �� Ǯ���!
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, maze[100][100];
bool visited[100][100];
bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= N) return false;
    return true;
}
bool f(int r, int c, int lo, int hi) {
    if (r == N - 1 && c == N - 1) return true;
    visited[r][c] = true;
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (!isIn(nr, nc) || visited[nr][nc]) continue;
        if (maze[nr][nc] > hi || maze[nr][nc] < lo) continue;
        if (f(nr, nc, lo, hi)) return true;
    }
    return false;
}
int main() {
    int mx = 0, mn = 200;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
            mn = min(mn, maze[i][j]);
            mx = max(mx, maze[i][j]);
        }
    }
    int ans = mx - mn;
    int lo = mn, hi = maze[0][0];
    while (lo <= maze[0][0] && hi <= mx) {
        memset(visited, false, sizeof(visited));
        if (f(0, 0, lo, hi)) {
            ans = min(ans, hi - lo);
            lo++;
        } else {
            hi++;
        }
    }
    printf("%d", ans);
}