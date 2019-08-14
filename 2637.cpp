#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
using p = pair<int,int>;
int N, M;
int in[100];
vector<p> adj[100];
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++){
        int X, Y, K;
        scanf("%d %d %d", &X, &Y, &K);
        X--, Y--;
        adj[Y].push_back({X, K});
        in[X]++;
    }
    queue<int> q;
    vector<int> base;
    int need[100][100]{};
    for (int i = 0; i < N; i++){
        if (!in[i]) {
            q.push(i);
            need[i][i] = 1;
            base.push_back(i);
        }
    }
    for (int i = 0; i < N; i++){
        int curr = q.front();
        q.pop();
        for (auto pNext : adj[curr]){
            int next = pNext.first;
            int cost = pNext.second;
            for (int b : base) need[next][b] += need[curr][b] * cost;
            if (--in[next] == 0) q.push(next);
        }
    }
    for (int b : base) {
        printf("%d %d\n", b + 1, need[N - 1][b]);
    }
}