#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int in[32000];
vector<int> adj[32000];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        in[v - 1]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (!in[i]) q.push(i);
    }
    vector<int> res;
    for (int i = 0; i < n; i++){
        int curr = q.front();
        q.pop();
        res.push_back(curr + 1);
        for (int next : adj[curr]){
            if (--in[next] == 0) q.push(next);
        }
    }
    for (int curr : res) printf("%d ", curr);
}