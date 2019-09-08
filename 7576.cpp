#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
const int roff[] = {-1,1,0,0};
const int coff[] = {0,0,-1,1};
int tomato[1000][1000], n, m, S;
bool isIN(int r, int c){
    if (r < 0 || c < 0 || r >= n || c >= m) return false;
    return true;
}
int bfs(vector<p> &pv){
    queue<p> q;
    bool visited[1000][1000]{};
    for (auto pCurr : pv){
        q.push(pCurr);
        visited[pCurr.first][pCurr.second] = true;
    }
    int ret = 0;
    for (; !q.empty(); ret++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            auto pCurr = q.front();
            int r = pCurr.first;
            int c = pCurr.second;
            S--;
            q.pop();
            for (int d = 0; d < 4; d++){
                int nr = r + roff[d];
                int nc = c + coff[d];
                if (!isIN(nr, nc) || visited[nr][nc] || tomato[nr][nc]) continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    return ret - 1;
}
int main(){
    scanf("%d %d", &m,&n);
    S = m * n;
    vector<p> loca;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j] == 1) loca.push_back({i,j});
            if (tomato[i][j] == -1) S--;
        }
    }
    int ret = bfs(loca);
    printf("%d\n", S ? -1 : ret);
}