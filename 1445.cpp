#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int roff[] = {-1, 1, 0, 0};
const int coff[] = {0, 0, -1, 1};
int N, M, iMaze[50][50];
char cMaze[50][50];
bool isPossible(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}
void fillArray(int r, int c) {
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (isPossible(nr, nc) && !iMaze[nr][nc] && cMaze[nr][nc] == '.') {
            iMaze[nr][nc] = 1;
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    p S, E;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &cMaze[i][j]);
            if (cMaze[i][j] == 'S') S = {i, j};
            if (cMaze[i][j] == 'F') E = {i, j};
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cMaze[i][j] == 'g') {
                iMaze[i][j] = 2500;
                fillArray(i, j);
            }
        }
    }
    priority_queue<p, vector<p>, greater<p>> pq;
    bool visited[2500]{};
    int dist[2500]{}, start, end;
    memset(dist, INF, sizeof(dist));
    start = S.first * M + S.second;
    end = E.first * M + E.second;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int curr;
        do {
            curr = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visited[curr]);
        if (visited[curr]) break;
        visited[curr] = true;
        int r = curr / M, c = curr % M;
        for (int d = 0; d < 4; d++) {
            int nr = r + roff[d];
            int nc = c + coff[d];
            if (!isPossible(nr, nc)) continue;
            int next = nr * M + nc;
            if (dist[next] >= dist[curr] + iMaze[r][c]) {
                dist[next] = dist[curr] + iMaze[r][c];
                pq.push({dist[next], next});
            }
        }
    }
    printf("%d %d", dist[end] / 2500, dist[end] % 2500);
}