/*
�ð����⵵ : O(N^2)

S�� �ڿ� (R, C)�� ��ǥ�� � ���̷����� �ִ��� Ȯ���ϴ� �����̴�.
���� ���̷����� �ʱ⿡ Ư�� ��ġ�� �ִµ�, ��ũ���ǿ� ������ ��ȣ�� ���� ������
���̷����� ���� �����ϴ� Ư¡�� ������ �ִ�.
ť�� �־��� ��, ó������ ������ �Ǿ��ִ� ���·� �־��شٸ�
bfs�� �ϴ� ���ȿ��� ������ �Ǿ��ִ� ���·� push, pop�ϰ� �ȴ�.
����, �ʱ⿡ �� ���� ���ķ� ���� �� ���� ������ ������ ���°� �ǹǷ�,
�Ź� ������ �� �ʿ䰡 ��������.
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