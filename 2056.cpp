#include <bits/stdc++.h>
using namespace std;
int N, in[10010], T[10010], res[10010];
vector<int> adj[10010];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", T + i, in + i);
        for (int s = 0; s < in[i]; s++) {
            int j;
            scanf("%d", &j);
            adj[j].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {
            q.push(i);
            res[i] = T[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            res[next] = max(res[next], res[curr] + T[next]);
            if (--in[next] == 0) q.push(next);
        }
    }
    printf("%d\n", *max_element(res, res + N + 1));
}