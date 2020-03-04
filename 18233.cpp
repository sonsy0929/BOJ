#include <bits/stdc++.h>
using namespace std;
int N, P, E, x[20], y[20];
int main() {
    scanf("%d %d %d", &N, &P, &E);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", x + i, y + i);
    }
    vector<int> ans;
    for (int b = 1; b < (1 << N); b++) {
        if (__builtin_popcount(b) != P) continue;
        vector<int> tracking(N, 0);
        int sum = 0, xSum = 0, ySum = 0;
        for (int i = 0; i < N; i++) {
            if (b & (1 << i)) {
                tracking[i] += x[i];
                sum += x[i];
                xSum += x[i], ySum += y[i];
            }
        }
        if (xSum <= E && E <= ySum) {
            for (int i = 0; i < N; i++) {
                if (!tracking[i]) continue;
                int add = min(y[i] - x[i], E - sum);
                tracking[i] += add;
                sum += add;
            }
            ans = tracking;
            break;
        }
    }
    if (ans.empty()) {
        puts("-1");
    } else {
        for (int curr : ans) {
            printf("%d ", curr);
        }
    }
}