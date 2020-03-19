/*
�ð����⵵ : O(N * M)

�κ� û�ұ��� ���� ����� �����ϰ� �����ϸ� �ȴ�.
�κ� û�ұ��� ������ ���ߴ� ����, ������ ���� �� ���� �ε����� ����̴�.
���� ������ �������� ���� -> �ݽð� ������ �ǹ��Ѵ�
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, 1, 0, -1};
int N, M, r, c, d, maze[50][50];
int main() {
    fastio;
    cin >> N >> M >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    int ans = 0;
    while (maze[r][c] != 1) {
        ans += !maze[r][c];
        maze[r][c] = 2;
        bool possible = false;
        for (int i = 0; !possible && i < 4; i++) {
            d = (d + 3) % 4;
            int nr = r + roff[d], nc = c + coff[d];
            if (maze[nr][nc]) continue;
            possible = true;
            r = nr, c = nc;
        }
        if (!possible) {
            r -= roff[d];
            c -= coff[d];
        }
    }
    cout << ans;
}