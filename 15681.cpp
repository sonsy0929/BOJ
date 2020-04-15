#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int SZ = 100'010;
int N, R, Q, dp[SZ];
vector<int> g[SZ];
int f(int curr, int parent = 0) {
    int &ret = dp[curr];
    if (ret != -1) return ret;
    ret = 1;
    for (int next : g[curr]) {
        if (parent == next) continue;
        ret += f(next, curr);
    }
    return ret;
}
int main() {
    fastio;
    cin >> N >> R >> Q;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    f(R);
    for (int i = 0, u; i < Q; i++) {
        cin >> u;
        cout << dp[u] << "\n";
    }
}