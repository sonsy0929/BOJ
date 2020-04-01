/*
시간복잡도 : O(N * M * 5 * 4) -> O(N * M * 4^3)

'ㅜ' 모양을 빼고는 시작좌표에서 dfs를 돌려서 모양을 구할 수 있다.(회전 포함)

실수한 부분 :

1) zero-padding
테두리 부분에 0으로 채우면, 블록이 밖으로 삐져나오는 것을 허용해도 될 것이라는
말도 안되는 착각을 함.
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, M, score[501][501], mx;
bool isIn(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}
void f(int curr, int prev, int depth, int sum) {
    if (depth == 3) {
        mx = max(mx, sum);
        return;
    }
    int r, c, pr, pc;
    r = curr / M, c = curr % M;
    pr = prev / M, pc = prev % M;
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (!isIn(nr, nc) || (nr == pr && nc == pc)) continue;
        f(nr * M + nc, r * M + c, depth + 1, sum + score[nr][nc]);
    }
}
int hShape(int r, int c) {
    int ret = 0;
    const p offset[4][3] = {
        {{0, 1}, {0, -1}, {-1, 0}},
        {{1, 0}, {0, -1}, {0, 1}},
        {{0, -1}, {1, 0}, {-1, 0}},
        {{0, 1}, {-1, 0}, {1, 0}}
    };
    for (int d = 0; d < 4; d++) {
        int sum = score[r][c];
        bool possible = true;
        for (auto [dr, dc] : offset[d]) {
            int nr = r + dr, nc = c + dc;
            if (!isIn(nr, nc)) {
                possible = false;
                break;
            }
            sum += score[nr][nc];
        }
        if (possible) ret = max(sum, ret);
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &score[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            f(i * M + j, -1, 0, score[i][j]);
            mx = max(mx, hShape(i, j));
        }
    }
    printf("%d", mx);
}