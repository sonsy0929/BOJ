#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[1000];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int cnt, in[1000]{};
    for (int i = 0; i < m; i++){
        scanf("%d", &cnt);
        vector<int> v;
        for (int j = 0; j < cnt; j++){
            int val;
            scanf("%d", &val);
            v.push_back(val - 1);
        }
        int prev = v[0];
        for (int j = 1; j < v.size(); j++){
            in[v[j]]++;
            adj[prev].push_back(v[j]);
            prev = v[j];
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (!in[i]) q.push(i);
    }
    vector<int> order;
    bool possible = true;
    for (int i = 0; i < n; i++){
        if (q.empty()) {
            possible = false;
            break;
        }
        int curr = q.front();
        q.pop();
        order.push_back(curr);
        for (int next : adj[curr]){
            if (--in[next] == 0) q.push(next);
        }
    }
    if (!possible) puts("0");
    else {
        for (int curr : order) printf("%d\n", curr + 1);
    }
}