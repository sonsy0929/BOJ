#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int K, M, P;
        scanf("%d %d %d", &K, &M, &P);
        int in[1000]{};
        vector<int> adj[1000];
        for (int i = 0; i < P; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            in[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        int order[1000]{};
        for (int i = 0; i < M; i++){
            if (!in[i]) {
                q.push(i);
                order[i]++;
            }
        }
        int cnt[1000];
        fill(cnt, cnt + 1000, 1);
        for (int i = 0; i < M; i++){
            int curr = q.front();
            q.pop();
            if (cnt[curr] > 1) order[curr]++;
            for (int next : adj[curr]){
                if (order[next] <= order[curr]){
                    if (order[next] == order[curr]) cnt[next]++;
                    else cnt[next] = 1;
                    order[next] = order[curr];
                }
                if (--in[next] == 0) q.push(next);
            }
        }
        printf("%d %d\n", K, order[M - 1]);
    }
}