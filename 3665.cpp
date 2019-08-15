#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d", &n);
        int rank[500]{}, origin[500]{};
        vector<int> adj[500];
        for (int i = 0; i < n; i++){
            int val;
            scanf("%d", &val);
            rank[val - 1] = i;
            origin[i] = val - 1;
        }
        int in[500]{};
        bool used[500][500]{};
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            if (rank[u] < rank[v]) swap(u, v);
            adj[u].push_back(v);
            in[v]++;
            used[v][u] = true;
        }
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int u = origin[i], v = origin[j];
                if (used[u][v]) continue;
                adj[u].push_back(v);
                in[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (!in[i]) q.push(i);  
        }
        bool possible = true, isCertain = true;
        vector<int> order;
        for (int i = 0; i < n; i++){
            if (q.empty()) {
                possible = false;
                break;
            }
            if (q.size() > 1) isCertain = false;
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for (int next : adj[curr]){
                if (--in[next] == 0) q.push(next);
            }
        }
        if (!possible) puts("IMPOSSIBLE");
        else {
            if (isCertain) {
                for (int curr : order) printf("%d ", curr + 1);
                puts("");
            }
            else puts("?");
        }
    }
}