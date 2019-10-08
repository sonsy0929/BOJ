#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int SIZE = 10;
const int roff[] = {-1,1,0,0};
const int coff[] = {0,0,-1,1};
int N, M, maze[SIZE][SIZE], ans;
vector<p> virus, wall;
bool isPossible(int r, int c){
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}
int bfs(){
    queue<p> q;
    bool visited[SIZE][SIZE]{};
    bool isWall[SIZE][SIZE]{};
    for (auto pCurr : virus){
        int r, c;
        tie(r, c) = pCurr;
        q.push(pCurr);
        visited[r][c] = true;
    }
    for (auto pCurr : wall){
        int r, c;
        tie(r, c)= pCurr;
        isWall[r][c] = true;
    }
    int cnt = 0;
    while(!q.empty()){
        int r, c;
        tie(r, c) = q.front();
        q.pop();
        cnt++;
        for (int d = 0; d < 4; d++){
            int nr = r + roff[d];
            int nc = c + coff[d];
            if (!isPossible(nr,nc) || visited[nr][nc] || isWall[nr][nc]) continue;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
    return N * M - (cnt + wall.size());
}
void comb(int cnt, int r, int c){
    if (cnt == 3){
        ans = max(ans, bfs());
        return;
    }
    for (int i = r; i < N; i++){
        for (int j = (i == r ? c : 0); j < M; j++){
            if (maze[i][j]) continue;
            wall.push_back({i,j});
            comb(cnt+1, i, j);
            wall.pop_back();
        }
    }
}
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d", &maze[i][j]);
            if (maze[i][j] == 1) wall.push_back({i,j});
            if (maze[i][j] == 2) virus.push_back({i,j});
        }
    }
    comb(0, 0, 0);
    printf("%d\n", ans);
}