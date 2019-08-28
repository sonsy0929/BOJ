#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 200'000;
const int INF = 1e9;
int N, K, M;
vector<int> adj[SIZE];
int bfs(){
    queue<int> q;
    int cnt[SIZE]{};
    q.push(0);
    cnt[0] = 1;
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        if (curr == N - 1) return cnt[curr];
        for (int next : adj[curr]){
            if (cnt[next]) continue;
            q.push(next);
            cnt[next] = cnt[curr] + 1;
        }
    }
    return -1;
}
int main(){
    scanf("%d %d %d", &N, &K, &M);
    int dummy = N;
    for (int i = 0; i < M; i++){
        vector<int> tmp;
        for (int j = 0; j < K; j++){
            int in;
            scanf("%d", &in);
            tmp.push_back(in-1);
        }
        for (int curr : tmp){
            adj[curr].push_back(dummy+i);
            adj[dummy+i].push_back(curr);
        }
    }
    int ret = bfs();
    if (ret != - 1) printf("%d\n", (ret + 1) / 2);
    else puts("-1");
}