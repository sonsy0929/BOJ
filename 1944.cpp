/*
복제가 가능하고, S ~ K 간의 간선이 형성되는 것을 확인할 수 있다.
이를 통해, 모든 열쇠를 찾아 로봇이 움직이는 횟수의 합이 최소가 됨은
MST와 동치라는 것을 확인할 수 있고 이를 구할 수 있다.
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
using tup = tuple<int,int,int>;
constexpr int SIZE = 50;
constexpr int roff[] = {-1,1,0,0};
constexpr int coff[] = {0,0,-1,1};
char maze[SIZE][SIZE];
vector<p> graph;
vector<tup> edges;
int uf[SIZE*SIZE], N, M;
int getIdx(p point){
    return point.first * SIZE + point.second;
}
bool isPossible(int r, int c){
    if (r < 0 || c < 0 || r >= N || c >= N) return false;
    return true;
}
bool isVertex(int r, int c){
    return maze[r][c] == 'S' || maze[r][c] == 'K';
}
void bfs(p start){
    queue<p> q;
    bool visited[SIZE][SIZE]{};
    q.push(start);
    int dist = 0, r, c;
    for (; !q.empty(); dist++){
        int qSize = q.size();
        for (int s = 0; s < qSize; s++){
            tie(r, c) = q.front();
            q.pop();
            if (dist && isVertex(r, c)) edges.push_back({dist, getIdx(start), getIdx({r,c})});
            for (int d = 0; d < 4; d++){
                int nr = r + roff[d];
                int nc = c + coff[d];
                if (!isPossible(nr, nc) || visited[nr][nc] || maze[nr][nc] == '1') continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}
int find(int n){
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    uf[a] = b;
    return true;
}
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'S' || maze[i][j] == 'K') graph.push_back({i,j});
        }
    }
    for (auto pCurr : graph){
        bfs(pCurr);
    }
    sort(edges.begin(), edges.end());
    memset(uf, -1, sizeof(uf));
    int ans = 0, cnt = 0;
    for (auto tCurr : edges){
        int d,u,v;
        tie(d,u,v) = tCurr;
        if (merge(u, v)){
            ans += d;
            if (++cnt == M) break;
        }
    }
    printf("%d\n", cnt == M ? ans : -1);
}