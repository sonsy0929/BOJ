#include <bits/stdc++.h>
using namespace std;
int Q;
deque<int> curr[4];
void rotate(deque<int>& D, int d) {
    if (d == -1) {
        D.push_back(D.front());
        D.pop_front();
    } else {
        D.push_front(D.back());
        D.pop_back();
    }
}
void solve(int k, int d) {
    deque<int> next[4];
    for (int i = 0; i < 4; i++) {
        for (int e : curr[i]) {
            next[i].push_back(e);
        }
    }
    rotate(next[k], d);
    for (int i = k - 1, nd = d; i >= 0; i--, nd *= -1) {
        if (curr[i + 1][6] == curr[i][2]) break;
        rotate(next[i], nd * (-1));
    }
    for (int i = k + 1, nd = d; i < 4; i++, nd *= -1) {
        if (curr[i - 1][2] == curr[i][6]) break;
        rotate(next[i], nd * (-1));
    }
    swap(curr, next);
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            int in;
            scanf("%1d", &in);
            curr[i].push_back(in);
        }
    }
    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        int k, d;
        scanf("%d %d", &k, &d);
        solve(k - 1, d);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += curr[i][0] ? 1 << i : 0;
    }
    printf("%d", ans);
}