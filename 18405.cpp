/*
시간복잡도 : O(N^2)

S초 뒤에 (R, C)의 좌표에 어떤 바이러스가 있는지 확인하는 문제이다.
여러 바이러스가 초기에 특정 위치에 있는데, 디스크립션에 따르면 번호가 낮은 종류의
바이러스가 먼저 증식하는 특징을 가지고 있다.
큐에 넣어줄 때, 처음부터 정렬이 되어있는 상태로 넣어준다면
bfs를 하는 동안에도 정렬이 되어있는 상태로 push, pop하게 된다.
따라서, 초기에 한 번의 정렬로 인해 매 순간 정렬이 유지된 상태가 되므로,
매번 정렬을 할 필요가 없어진다.
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, K, maze[200][200];
bool isIn(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
}
int main() {
    scanf("%d %d", &N, &K);
    deque<p> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
            if (maze[i][j]) {
                q.push_back({maze[i][j], i * N + j});
            }
        }
    }
    sort(q.begin(), q.end());
    int s, r, c;
    scanf("%d %d %d", &s, &r, &c);
    for (int t = 0; !q.empty() && t < s; t++) {
        int qSize = q.size();
        for (int s = 0; s < qSize; s++) {
            auto [w, p] = q.front();
            int r = p / N, c = p % N;
            q.pop_front();
            for (int d = 0; d < 4; d++) {
                int nr = r + roff[d];
                int nc = c + coff[d];
                if (!isIn(nr, nc) || maze[nr][nc]) continue;
                maze[nr][nc] = maze[r][c];
                q.push_back({maze[nr][nc], nr * N + nc});
            }
        }
    }
    printf("%d\n", maze[r - 1][c - 1]);
}