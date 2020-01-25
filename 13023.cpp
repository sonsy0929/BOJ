/*
5 5
1 2
2 4
2 3
3 4
4 5
*/
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj[2010];
bool visited[2010];
bool dfs(int curr, int cnt) {
    if (cnt >= 4) return true;
    visited[curr] = true;
    for (int next : adj[curr]) {
        if (!visited[next]) {
            if (dfs(next, cnt + 1)) return true;
        }
    }
    visited[curr] = false;
    return false;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool possible = false;
    for (int i = 0; i < N; i++) {
        if (dfs(i, 0)) {
            possible = true;
            break;
        };
    }
    printf("%d\n", possible);
}