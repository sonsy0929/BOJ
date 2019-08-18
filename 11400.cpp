#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 100'000;
vector<int> adj[SIZE + 1];
vector<p> res;
int visited[SIZE + 1], order;
int f(int curr, int parent){
    visited[curr] = ++order;
    int ret = visited[curr];
    for (int next : adj[curr]){
        if (next == parent) continue;
        if (!visited[next]){
            int k = f(next, curr);
            if (k > visited[curr]) res.push_back({min(curr, next), max(curr, next)});
            ret = min(ret, k);
        }
        else ret = min(ret, visited[next]);
    }
    return ret;
}
int main(){
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= V; i++){
        if (!visited[i]) f(i, 0);
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for (auto pCurr : res) printf("%d %d\n", pCurr.first, pCurr.second);
}