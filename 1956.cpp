#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 400;
const int INF = 0x3f3f3f3f;
int dist[SIZE][SIZE];
int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    memset(dist, INF, sizeof(dist));
    for (int i = 0; i < e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        dist[a][b] = c;
    }
    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    
    int ans = INF;
    for (int i = 0; i < v; i++) ans = min(ans, dist[i][i]);
    printf("%d\n", ans != INF ? ans : -1);
}