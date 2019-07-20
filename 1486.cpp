#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, M, T, D;
char map[25][25];
int dist[700][700];
int getVal(char c){
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a' + 26; 
}
int getDiff(int u, int v){
    return u - v;
}
bool possible(int r, int c){
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}
void init(){
    for (int i = 0; i < N * M; i++){
        for (int j = 0; j < N * M; j++){
            if (i == j) continue;
            dist[i][j] = INF;
        }
    }
}
int main(){
    scanf("%d %d %d %d", &N, &M, &T, &D);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf(" %c", &map[i][j]);
        }
    }
    init();
    for (int r = 0; r < N; r++){
        for (int c = 0; c < M; c++){
            for (int d = 0; d < 4; d++){
                int nr = r + roff[d], nc = c + coff[d];
                if (!possible(nr, nc)) continue;
                int u = r * M + c, v = nr * M + nc;
                int diff = getDiff(getVal(map[r][c]), getVal(map[nr][nc]));
                if (abs(diff) > T) continue;
                else if (diff >= 0) dist[u][v] = 1;
                else dist[u][v] = diff * diff;
            }
        }
    }
    for (int k = 0; k < N * M; k++){
        for (int i = 0; i < N * M; i++){
            for (int j = 0; j < N * M; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    // 호텔이 산에 위치하고 있어서 호텔도 포함해야 한다
    for (int i = 0; i < N * M; i++){
        int val = dist[0][i] + dist[i][0];
        if (val > D) continue;
        ans = max(ans, getVal(map[i / M][i % M])); 
    }    
    printf("%d\n", ans);
}