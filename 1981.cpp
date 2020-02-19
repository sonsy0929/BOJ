/*
시간복잡도 : O(k * N^2)

투 포인터 + dfs를 활용해서 풀이를 하였다.
(1, 1) -> (n, n)까지 이동하려 할 때, 최대값 - 최소값의 차이가 가장 작아지는 경우를 구해야 한다.
배열을 입력받으면서 최소값과 최대값을 갱신한다.
lo, hi 두 개의 포인터로 값을 조절하면서 hi - lo의 최소값을 구하면 된다.
만약 현재 lo, hi로 (1, 1) -> (n, n)에 도착이 가능하면, lo값을 증가
그렇지 않으면 hi값을 증가시키면서 hi - lo의 최소를 구해주면 된다.
비슷한 문제로는 집배원 한상덕이 있다고 한다. 한 번 풀어보자!
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