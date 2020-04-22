#include <bits/stdc++.h>
using namespace std;
using p = pair<int,int>;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int R, C; char maze[50][50];
p start, house;
vector<p> flood;
bool isIn(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}
int bfs() {
    using tup = tuple<int,int,bool>;
    queue<tup> q;
    bool visited[50][50]{}, isWater[50][50]{};
    for (auto [wr, wc] : flood) {
        q.push({wr, wc, 0});
        isWater[wr][wc] = true;
    }
    auto [sr,sc] = start;
    q.push({sr, sc, 1});
    visited[sr][sc] = true;
    for (int t = 0; !q.empty(); t++) {
        int qSize = q.size();
        for (int s = 0; s < qSize; s++) {
            auto [r, c, f] = q.front();
            q.pop();
            if (f && house == p(r, c)) return t;
            for (int d = 0; d < 4; d++) {
                int nr = r + roff[d], nc = c + coff[d];
                if (!isIn(nr, nc) || maze[nr][nc] == 'X') continue;
                if (f && (visited[nr][nc] || isWater[nr][nc])) continue;
                if (!f && (isWater[nr][nc] || maze[nr][nc] == 'D')) continue;
                q.push({nr, nc, f});
                if (f) visited[nr][nc] = true;
                else isWater[nr][nc] = true;
            }
        }
    }
    return -1;
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'D') house = {i,j};
            if (maze[i][j] == 'S') start = {i,j};
            if (maze[i][j] == '*') flood.push_back({i,j});
        }
    }
    int ret = bfs();
    if (ret != -1) cout << ret;
    else cout << "KAKTUS";
}