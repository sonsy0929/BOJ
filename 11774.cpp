/*
아이디어 문제?

양방향 경로가 이루어진 트리가 주어질 때, 경로를 전부 단방향으로 바꾸는데 어떻게 방향을 설정해야
최장경로가 제일 작아지는지를 묻는 문제

아무 정점이나 루트를 잡고 트리를 구축 했을 때 홀수 높이에 있는 정점은 간선의 방향을 outdegree로 
짝수 높이에 있는 정점은 간선의 방향을 indegree로 구축하면
항상 최장거리는 1이 된다.
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int SIZE = 100'000;
vector<int> adj[SIZE];
int depth[SIZE];
void dfs(int curr){
    for (int next : adj[curr]){
        if (depth[next] == -1){
            depth[next] = depth[curr] + 1;
            dfs(next);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> mol;
    for (int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mol.push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    depth[0] = 0;
    dfs(0);
    for (int curr : mol){
        printf("%d\n", depth[curr] & 1);
    }
}