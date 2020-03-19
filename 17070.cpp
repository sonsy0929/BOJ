/*
�ð����⵵ : O(N^2)

dp[r][c][state] : ���� ��ǥ�� (r, c)�̰� �������� ���°� state�� ��, (N, N)���� �����ϴ� ����� ��

�ݺ��Ǵ� ȣ���� memoization�� ���� dp�迭�� ������ �ؼ�,
����� ���� �ִ� �κ��� �߰������� �Լ��� ȣ������ �ʵ��� �ߴ�.
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