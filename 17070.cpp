/*
시간복잡도 : O(N^2)

dp[r][c][state] : 현재 좌표가 (r, c)이고 파이프의 상태가 state일 때, (N, N)으로 도달하는 경우의 수

반복되는 호출은 memoization을 통해 dp배열에 저장을 해서,
계산한 적이 있는 부분은 추가적으로 함수를 호출하지 않도록 했다.
*/

#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int>;
int N, maze[20][20], dp[20][20][3];
vector<tup> offset[3];
void init() {
    memset(dp, -1, sizeof(dp));
    offset[0] = {{0, 1, 0}, {1, 1, 2}};
    offset[1] = {{1, 0, 1}, {1, 1, 2}};
    offset[2] = {{0, 1, 0}, {1, 0, 1}, {1, 1, 2}};
}
bool isIn(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}
bool isSafe(int r, int c) {
    return !maze[r + 1][c] && !maze[r][c + 1];
}
int f(int r, int c, int state) {
    if (r == N - 1 && c == N - 1) return 1;
    int& ret = dp[r][c][state];
    if (ret != -1) return ret;
    ret = 0;
    for (auto [roff, coff, ns] : offset[state]) {
        int nr = r + roff, nc = c + coff;
        if (!isIn(nr, nc) || maze[nr][nc]) continue;
        if (roff && coff && !isSafe(r, c)) continue;
        ret += f(nr, nc, ns);
    }
    return ret;
}
int main() {
    init();
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    printf("%d", f(0, 1, 0));
}