/*
�ð����⵵ : O(150 * 1200 * 4)

�迭�� ȸ���� ��, ū �׵θ����� �����ؼ� ���� �׵θ����� 
�� ȸ���� ���ε��� �ϴ� ������� �����Ͽ���.
Ư��, in-place ������� ������ �ϱ� ���� �ݽð� �������� ��ȸ�� �ϴ� ���� �ƴ�,
�ð� �������� ��ȸ�� �ϸ鼭 �迭�� ���� �ٲپ� �־���.
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