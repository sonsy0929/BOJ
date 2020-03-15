#include <bits/stdc++.h>
using namespace std;
int N, X[100], Y[100];
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", X + i, Y + i);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (Y[i] == Y[j] && X[j] == X[k]) {
                    int w = abs(X[i] - X[j]);
                    int h = abs(Y[j] - Y[k]);
                    ans = max(ans, w * h);
                }
            }
        }
    }
    printf("%d", ans);
}