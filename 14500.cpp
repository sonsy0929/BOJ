/*
�ð����⵵ : O(N * M * 5 * 4) -> O(N * M * 4^3)

'��' ����� ����� ������ǥ���� dfs�� ������ ����� ���� �� �ִ�.(ȸ�� ����)

�Ǽ��� �κ� :

1) zero-padding
�׵θ� �κп� 0���� ä���, ����� ������ ���������� ���� ����ص� �� ���̶��
���� �ȵǴ� ������ ��.
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