#include <cstdio>
#include <algorithm>
using namespace std;
int R, C, w_cnt, s_cnt;
bool visited[250][250];
char map[250][250];
const int roff[] = { -1, 1, 0, 0 };
const int coff[] = { 0, 0, -1, 1 };
bool inPos(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) return false;
	return true;
}
void dfs(int r, int c) {
	visited[r][c] = true;
	w_cnt += (map[r][c] == 'v');
	s_cnt += (map[r][c] == 'o');
	for (int d = 0; d < 4; d++) {
		int nr = r + roff[d], nc = c + coff[d];
        if (!inPos(nr, nc)) continue;
		if (map[nr][nc] == '#' || visited[nr][nc]) continue;
        dfs(nr, nc);
	}
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) scanf(" %c", &map[i][j]);
	int ans[2]{};
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && !visited[i][j]) {
				w_cnt = 0, s_cnt = 0;
                dfs(i, j);
                ans[0] += s_cnt > w_cnt ? s_cnt : 0;
                ans[1] += s_cnt > w_cnt ? 0 : w_cnt;
			}
		}
	}
	printf("%d %d\n", ans[0], ans[1]);
}
