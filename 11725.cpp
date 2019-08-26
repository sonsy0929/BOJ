#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int SIZE = 100'000;
vector<int> adj[SIZE];
int pa[SIZE];
void dfs(int curr){
    for (int next : adj[curr]){
        if (pa[next] == -1){
            pa[next] = curr;
            dfs(next);
        }
    }
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(pa, -1, sizeof(pa));
    dfs(0);
    for (int i = 1; i < N; i++) printf("%d\n", pa[i] + 1);
}