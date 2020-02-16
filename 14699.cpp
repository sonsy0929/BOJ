/*
시간복잡도 : O(N + M)

위상정렬로도 가능한 문제라고 하는데,, dfs + dp로 바로 접근을 했기 때문에 이와 같은 방식으로 풀었다.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[5010];
int N, M, height[5010], dp[5010];
int f(int curr) {
    int &ret = dp[curr];
    if (ret != -1) return ret;
    ret = 1;
    for (int next : adj[curr]) {
        if (height[next] <= height[curr]) continue;
        ret = max(ret, f(next) + 1);
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", height + i);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", f(i));
    }
}