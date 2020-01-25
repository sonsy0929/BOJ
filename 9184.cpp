#include <bits/stdc++.h>
using namespace std;
int A, B, C, dp[21][21][21];
int f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);
    int &ret = dp[a][b][c];
    if (ret != -1) return ret;
    if (a < b && b < c) return ret = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    return ret = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
}
int main() {
    while (1) {
        scanf("%d %d %d", &A, &B, &C);
        if (A == -1 && B == -1 && C == -1) break;
        memset(dp, -1, sizeof(dp));
        printf("w(%d, %d, %d) = %d\n", A, B, C, f(A, B, C));
    }
}