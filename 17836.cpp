/*
�ð����⵵ : O(NM)

�������� bfs ����

�Ǽ��� �κ�)
hasGram |= (maze[nr][nc] == 2)
�̷� ������ �ڵ带 �ۼ��ؼ� ������¿� ������ �ְ� �ڵ带 �ۼ�
���� ������ �� ������ Ȯ���ϸ鼭 ������ �߻��� �� ����.
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
    queue<tup> q;   // element : {��, ��, �׶��� ������ �ִ��� ����}
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
                    // �׶��� ������ ���� �� �� �ִ�
                    q.push({nr, nc, hasGram});
                    visited[nr][nc][hasGram] = true;
                } else {
                    // �׶��� ���� ���� ���� ��� X
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