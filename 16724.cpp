#include <cstdio>
#include <cstring>
using namespace std;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int idx[128], uf[1000 * 1000];
char map[1000][1000];
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return;
    uf[v] = u;
}
int main(){
    idx['D'] = 1, idx['U'] = 0, idx['L'] = 2, idx['R'] = 3;
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf(" %1c", &map[i][j]);
        }
    }
    memset(uf, -1, sizeof(uf));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            char c = map[i][j];
            int ni = i + roff[idx[c]];
            int nj = j + coff[idx[c]];
            int curr = i * M + j, next = ni * M + nj;
            merge(curr, next);
        }
    }
    int ans = 0;
    for (int i = 0; i < N * M; i++){
        if (uf[i] < 0) ans++;
    }
    printf("%d\n", ans);
}