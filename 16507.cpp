#include <bits/stdc++.h>
using namespace std;
int R, C, Q, pSum[1001][1001];
int main() {
    scanf("%d %d %d", &R, &C, &Q);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int in;
            scanf("%d", &in);
            pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + in;
        }
    }
    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int sum = pSum[r2][c2] - pSum[r1 - 1][c2] - pSum[r2][c1 - 1] + pSum[r1 - 1][c1 - 1];
        printf("%d\n", sum / ((r2 - r1 + 1) * (c2 - c1 + 1)));
    }
}