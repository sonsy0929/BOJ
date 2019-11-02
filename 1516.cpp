#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAXSIZE = 500;
int N, in[MAXSIZE], w[MAXSIZE], constructTime[MAXSIZE];
vector<int> adj[MAXSIZE];
int main(){
    scanf("%d", &N);
    int u, time;
    for (int i = 0; i < N; i++){
        scanf("%d", &time);
        w[i] = time;
        constructTime[i] = time;
        while (1){
            scanf("%d", &u);
            if (u == -1) break;
            adj[u-1].push_back(i);
            in[i]++;
        }
    }
    queue<int> Q;
    for (int i = 0; i < N; i++){
        if (!in[i]) Q.push(i);
    }
    for (int i = 0; i < N; i++){
        int curr = Q.front();
        Q.pop();
        for (int next : adj[curr]){
            constructTime[next] = max(constructTime[next], constructTime[curr] + w[next]);
            if (--in[next] == 0){
                Q.push(next);
            }
        }
    }
    for (int i = 0; i < N; i++){
        printf("%d\n", constructTime[i]);
    }
}