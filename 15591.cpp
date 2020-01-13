#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
constexpr int SIZE = 5010;
constexpr int INF = 0x3f3f3f3f;
vector<p> adj[SIZE];
int cnt = 0;
bool visited[SIZE];
void dfs(int curr, int K, int val){
    visited[curr] = true;
    for (auto pNext : adj[curr]){
        int next = pNext.first;
        int w = pNext.second;
        if (!visited[next]){
            if (min(val, w) >= K) cnt++;
            dfs(next, K, min(val, w));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,Q;
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i = 0; i < Q; i++){
        int k,v;
        cin >> k >> v;
        cnt = 0;
        memset(visited, false, sizeof(visited));
        dfs(v, k, INF);
        cout << cnt << "\n";
    }
}