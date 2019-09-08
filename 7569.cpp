#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using tup = tuple<int,int,int>;
const int roff[] = {-1,1,0,0,0,0};
const int coff[] = {0,0,-1,1,0,0};
const int hoff[] = {0,0,0,0,-1,1};
int tomato[100][100][100], n, m, h, S;
bool isIN(int k, int r, int c){
    if (k < 0 || r < 0 || c < 0 || r >= n || c >= m || k >= h) return false;
    return true;
}
int bfs(vector<tup> &pv){
    queue<tup> q;
    bool visited[100][100][100]{};
    for (auto pCurr : pv){
        q.push(pCurr);
        int k, r, c;
        tie(k, r, c) = pCurr;
        visited[k][r][c] = true;
    }
    int ret = 0;
    for (; !q.empty(); ret++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            int k, r, c;
            tie(k,r,c) = q.front();
            S--;
            q.pop();
            for (int d = 0; d < 6; d++){
                int nk = k + hoff[d];
                int nr = r + roff[d];
                int nc = c + coff[d];
                if (!isIN(nk, nr, nc) || visited[nk][nr][nc] || tomato[nk][nr][nc]) continue;
                q.push({nk,nr,nc});
                visited[nk][nr][nc] = true;
            }
        }
    }
    return ret - 1;
}
int main(){
    scanf("%d %d %d", &m,&n,&h);
    S = m * n * h;
    vector<tup> loca;
    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                scanf("%d", &tomato[k][i][j]);
                if (tomato[k][i][j] == 1) loca.push_back({k,i,j});
                if (tomato[k][i][j] == -1) S--;
            }
        }
    }
    int ret = bfs(loca);
    printf("%d\n", S ? -1 : ret);
}