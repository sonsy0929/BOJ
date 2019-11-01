#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int INF = 1e9;
int main(){
    int N, M, dist[200][200]{};
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &dist[i][j]);
            if (!dist[i][j]) dist[i][j] = INF;
        }
    }
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int travel[1000]{};
    for (int i = 0; i < M; i++) scanf("%d", travel+i);
    bool possible = true;
    for (int i = 0; i < M-1; i++){
        int u = travel[i], v = travel[i+1];
        possible &= (dist[u][v] != INF);
    }
    if (possible) puts("YES");
    else puts("NO");
}