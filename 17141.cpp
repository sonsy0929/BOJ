#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, M;
int maze[50][50], ans = 1e9, S;
vector<p> virus;
bool used[10];
int getCnt(){
    queue<p> q;
    bool visited[50][50]{};
    for (int i = 0; i < virus.size(); i++){
        if (!used[i]) continue;
        auto c = virus[i];
        q.push(c);
        visited[c.first][c.second] = true;
    }
    int cnt = 0, ret = 0;
    for (; !q.empty(); ret++) {
        int qSize = q.size();
        for (int s = 0; s < qSize; s++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cnt++;
            if (S - cnt == 0) return ret;
            for (int d = 0; d < 4; d++){
                int nr = r + roff[d], nc = c + coff[d];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (visited[nr][nc] || maze[nr][nc] == 1) continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    return 1e9;
}
void solve(int pos, int cnt){
    if (cnt > M) return;
    ans = min(ans, getCnt());
    for (int i = pos; i < virus.size(); i++){
        if (used[i]) continue;
        used[i] = true;
        solve(i + 1, cnt + 1);
        used[i] = false;
    }
}
int main(){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &maze[i][j]);
            if (maze[i][j] == 2) virus.push_back({i, j});
            if (maze[i][j] != 1) S++;
        }
    }
    solve(0, 0);
    printf("%d\n", ans != 1e9 ? ans : -1);
}