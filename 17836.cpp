/*
시간복잡도 : O(NM)

전형적인 bfs 문제

실수한 부분)
hasGram |= (maze[nr][nc] == 2)
이런 식으로 코드를 작성해서 현재상태에 영향을 주게 코드를 작성
이후 인접한 각 방향을 확인하면서 문제가 발생할 수 있음.
*/

#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int,int,int>;
int N, M, T, maze[100][100];
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
bool isIn(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}
int bfs() {
    queue<tup> q;   // element : {행, 열, 그람을 가지고 있는지 여부}
    bool visited[100][100][2]{};
    q.push({0, 0, 0});
    visited[0][0][0] = true;
    for (int t = 0; t <= T; t++) {
        int qSize = q.size();
        for (int s = 0; s < qSize; s++) {
            auto [r, c, hasGram] = q.front();
            q.pop();
            if (r == N - 1 && c == M - 1) return t;
            for (int d = 0; d < 4; d++) {
                int nr = r + roff[d], nc = c + coff[d];
                if (!isIn(nr, nc) || visited[nr][nc][hasGram]) continue;
                if (hasGram) {
                    // 그람만 있으면 어디든 갈 수 있다
                    q.push({nr, nc, hasGram});
                    visited[nr][nc][hasGram] = true;
                } else {
                    // 그람이 없을 때는 벽을 통과 X
                    if (maze[nr][nc] != 1) {
                        q.push({nr, nc, hasGram | (maze[nr][nc] == 2)});
                        visited[nr][nc][hasGram] = true;
                    }
                }
            }
        }
    }
    return -1;  // impossible
}
int main() {
    scanf("%d %d %d", &N, &M, &T);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    int ans = bfs();
    if (ans != -1) printf("%d", ans);
    else puts("Fail");
}