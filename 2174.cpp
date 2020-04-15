/*
시간복잡도 : O(M)

반성해야 할 점

1. 내가 생각한 (r, c)가 아니었다. => critical

1) 기존에 사용했던 (r, c)
  1 2 3 4 5
1 . . . . .
2 . . . . .
3 . . . . .
4 . . . . .
5 . . . . .


2) 문제에서 요구한 (r, c)
  1 2 3 4 5
5 . . . . .
4 . . . . .
3 . . . . .
2 . . . . .
1 . . . . .

계속 1)의 방법인 줄 알았으나, 문제를 자세히 보니까 2)의 방법이었다.
그래서 반례를 로봇이 (1, 1)에 있고 북쪽을 바라보고 있다면, 명령으로 1칸 이동하라는 명령이
들어오면 '벽에 부딪혔다' 라는 결과가 나오게 되었다..
시뮬레이션 문제를 풀 때는 문제를 제대로 읽어보자..
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using Robot = tuple<int,int,int>;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int R, C, N, M, visited[101][101];
vector<Robot> robots;
bool isIn(int r, int c) {
    return r > 0 && r <= R && c > 0 && c <= C;
}
bool doCommand(int x, char cmd, int cnt) {
    auto& [nr, nc, nd] = robots[x];
    auto [r, c, d] = robots[x];
    if (cmd == 'L') {
        cnt %= 4;
        while (cnt--) nd = (nd + 3) % 4;
    } else if (cmd == 'R') {
        cnt %= 4;
        while (cnt--) nd = (nd + 1) % 4;
    } else {
        for (int i = 0; i < cnt; i++) {
            nr += roff[d];
            nc += coff[d];
            if (!isIn(nr, nc)) {
                cout << "Robot " << x << " crashes into the wall";
                return false;
            }
            if (visited[nr][nc]) {
                cout << "Robot " << x << " crashes into robot " << visited[nr][nc];
                return false;
            }
        }
        visited[nr][nc] = x;
        visited[r][c] = 0;
    }
    return true;
}
int getDir(char c) {
    return string("NESW").find(c);
}
int main() {
    fastio;
    cin >> C >> R >> N >> M;
    robots.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int r, c; char d;
        cin >> c >> r >> d;
        r = R - r + 1;
        robots[i] = {r, c, getDir(d)};
        visited[r][c] = i;
    }
    int q = 0;
    for (; q < M; q++) {
        int X, cnt; char cmd;
        cin >> X >> cmd >> cnt;
        if (!doCommand(X, cmd, cnt)) break;
    }
    if (q == M) cout << "OK";
}