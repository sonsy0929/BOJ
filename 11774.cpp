/*
���̵�� ����?

����� ��ΰ� �̷���� Ʈ���� �־��� ��, ��θ� ���� �ܹ������� �ٲٴµ� ��� ������ �����ؾ�
�����ΰ� ���� �۾��������� ���� ����

�ƹ� �����̳� ��Ʈ�� ��� Ʈ���� ���� ���� �� Ȧ�� ���̿� �ִ� ������ ������ ������ outdegree�� 
¦�� ���̿� �ִ� ������ ������ ������ indegree�� �����ϸ�
�׻� ����Ÿ��� 1�� �ȴ�.
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