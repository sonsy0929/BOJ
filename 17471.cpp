#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int N, people[10], ans = 1e9;
vector<int> adj[10];
bool colored[10], visited[10];
int dfs(int n, bool flag){
    int ret = 1;
    visited[n] = true;
    for (int next : adj[n]){
        if (visited[next] || colored[next] != flag) continue;
        ret += dfs(next, flag);
    }
    return ret;
}
bool isPossible(bool flag){
    vector<int> v;
    for (int i = 0; i < N; i++){
        if (colored[i] == flag) v.push_back(i);
    }
    fill(visited, visited + 10, false);
    if (v.empty()) return false;
    int cnt = dfs(v.front(), flag);
    return cnt == v.size();
}
void f(int n){
    if (n == N){
        if (isPossible(true) && isPossible(false)){
            int r = 0, b = 0;
            for (int i = 0; i < N; i++){
                if (colored[i]) r += people[i];
                else b += people[i];
            }
            ans = min(ans, abs(r-b));
        }
        return;
    }
    colored[n] = true;
    f(n+1);
    colored[n] = false;
    f(n+1);
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", people+i);
    for (int i = 0; i < N; i++){
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            int v;
            scanf("%d", &v);
            adj[i].push_back(v-1);
            adj[v-1].push_back(i);
        }
    }
    f(0);
    printf("%d\n", ans != 1e9 ? ans : -1);
}