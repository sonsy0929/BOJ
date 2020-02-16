#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
int N, remain[40000], depth[40000], last;
vector<p> dot;
void fall(int lx, int rx, int ly, int ry) {
    for (int i = lx; i < rx; i++) remain[i] = 0;
    for (int i = lx - 1; i >= 0; i--) {
        if (depth[i] - remain[i] >= ly) continue;
        ly = min(depth[i], ly);
        remain[i] = max(0, depth[i] - ly);
    }
    for (int i = rx; i < last; i++) {
        if (depth[i] - remain[i] >= ry) continue;
        ry = min(depth[i], ry);
        remain[i] = max(0, depth[i] - ry);
    }
}
int main() {
    int r, c, K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &c, &r);
        dot.push_back({c, r});
    }
    for (int i = 0; i < N - 1; i++) {
        auto pCurr = dot[i];
        tie(c, r) = pCurr;
        last = max(last, c);
        if (i % 2) {
            for (int j = c; j < dot[i + 1].first; j++) {
                depth[j] = r;
                remain[j] = r;
            }
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        fall(a, c, b, d);
    }
    int ans = 0;
    for (int i = 0; i < last; i++) ans += remain[i];
    printf("%d", ans);
}