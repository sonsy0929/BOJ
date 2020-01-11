#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <functional>
using namespace std;
using p = pair<int,int>;
using tup = tuple<int,int,int>;
constexpr int SIZE = 100;
constexpr int roff[] = {0, -1, 0, 1};
constexpr int coff[] = {1, 0, -1, 0};
int turnIdx[4] = {0, 2, 3, 1};
int maze[SIZE][SIZE], R, C;
bool isPossible(int r, int c){
    if (r < 0 || c < 0 || r >= R || c >= C) return false;
    return true;
}
function<int(int)> f[2] = {
    [](int d){return (d + 1) % 4;},
    [](int d){return (d + 3) % 4;}
};
int bfs(tup start, tup end){
    queue<tup> q;
    q.push(start);
    set<tup> visited;
    visited.insert(start);
    int ret = 0;
    for (; !q.empty(); ret++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            auto curr = q.front();
            q.pop();
            int r, c, d;
            tie(r, c, d) = curr;
            if (curr == end) return ret;
            for (int i = 1; i <= 3; i++){
                int nr = r + roff[d] * i;
                int nc = c + coff[d] * i;
                if (!isPossible(nr, nc) || visited.count({nr,nc,d})) continue;
                if (maze[nr][nc]) break;
                visited.insert({nr,nc,d});
                q.push({nr,nc,d});
            }
            for (int i = 0; i < 2; i++){
                int nd = f[i](d);
                if (visited.count({r,c,nd})) continue;
                visited.insert({r,c,nd});
                q.push({r,c,nd});
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    vector<tup> info;
    for (int i = 0; i < 2; i++){
        int r, c, d;
        scanf("%d %d %d", &r, &c, &d);
        r--,c--,d--;
        info.push_back({r, c, turnIdx[d]});
    }
    printf("%d\n", bfs(info[0], info[1]));
}