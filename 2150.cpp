#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 10'000;
int V, E, order[SIZE], cnt, SCC_CNT = 0;
bool finished[SIZE];
stack<int> stk;
vector<int> adj[SIZE];
vector<vector<int>> SCC;
int dfs(int curr){
    order[curr] = cnt++;
    stk.push(curr);
    int minOrder = order[curr];
    for (int next : adj[curr]){
        if (order[next] == -1) minOrder = min(minOrder, dfs(next));
        else if (!finished[next]) minOrder = min(minOrder, order[next]); 
    }
    if (minOrder == order[curr]){
        vector<int> addV;
        while (!stk.empty()){
            int top = stk.top();
            if (top == curr) break;
            finished[top] = true;
            addV.push_back(top);
            stk.pop();
        }
        addV.push_back(curr);
        stk.pop();
        finished[curr] = true;
        sort(addV.begin(), addV.end());
        SCC.push_back(addV);
    }
    return minOrder;
}
int main(){
    memset(order, -1, sizeof(order));
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < V; i++){
        if (order[i] == -1) dfs(i); 
    }
    printf("%d\n", SCC.size());
    sort(SCC.begin(), SCC.end());
    for (auto v : SCC){
        for (int curr : v) printf("%d ", curr + 1);
        puts("-1");
    }
}