/*
시간복잡도 : O(150 * 1200 * 4)

배열을 회전할 때, 큰 테두리부터 시작해서 작은 테두리까지 
각 회전을 따로따로 하는 방식으로 구현하였다.
특히, in-place 방식으로 구현을 하기 위해 반시계 방향으로 순회를 하는 것이 아닌,
시계 방향으로 순회를 하면서 배열의 값을 바꾸어 주었다.
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, R, maze[300][300];
const int roff[] = {0, 1, 0, -1};
const int coff[] = {1, 0, -1, 0};
int main() {
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    int cnt = min(N, M) / 2;
    int Y = N - 1, X = M - 1;
    for (int i = 0; i < cnt; i++) {
        int L = 2 * (Y + X);
        int rot = R % L;
        const int go[2] = {X, Y};
        while (rot--) {
            int r = i, c = i;
            int start = maze[i][i];
            for (int d = 0; d < 4; d++) {
                for (int j = 0; j < go[d % 2]; j++) {
                    int pr = r + roff[d], pc = c + coff[d];
                    maze[r][c] = maze[pr][pc];
                    r += roff[d], c += coff[d];
                }
            }
            maze[i + 1][i] = start;
        }
        Y -= 2, X -= 2;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", maze[i][j]);
        }
        puts("");
    }
}