#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int t[1000]{}, in[1000]{};
        int buildTime[1000]{};
        vector<int> adj[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", t + i);
        }
        for (int i = 0; i < k; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            in[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!in[i]) q.push(i);
        }
        for (int i = 0; i < n; i++) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                buildTime[next] = max(buildTime[next], buildTime[curr] + t[curr]);
                if (--in[next] == 0) q.push(next);
            }
        }
        int w;
        scanf("%d", &w);
        printf("%d\n", buildTime[w - 1] + t[w - 1]);
    }
}