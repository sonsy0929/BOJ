#include <bits/stdc++.h>
using namespace std;
int N, K, V[3], ans;
void f(int p, int c) {
    if (p > 8) return;
    if (c <= N) ans = max(ans, c);
    for (int i = 0; i < K; i++) {
        f(p + 1, c * 10 + V[i]);
    }
}
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) scanf("%d", V + i);
    f(0, 0);
    printf("%d", ans);
}