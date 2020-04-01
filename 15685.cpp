/*
시간복잡도 : O(N * k)
k : 각 세대가 얼마나 성장할 수 있는지

K - 1 세대에서 K 세대로 성장하는데 규칙이 주어지며,
이는 귀납적으로 생각할 수 있음을 의미한다.
K - 1 세대의 방향들이 K 세대로 넘어올 때 위와 같이 기존의 방향들이 뒤에서부터 각각이 
반시계 방향으로 회전하는 것을 확인할 수 있다.
이를 통해 방향이 각 세대별로 쌓아가고 시작 좌표에서 방향에 따라 이동 하면서
방문처리를 해주면 된다. 그리고, 사각형을 형성하는지 100 * 100을 돌면서 확인하면 된다.
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int roff[] = {0, -1, 0, 1};
const int coff[] = {1, 0, -1, 0};
const int SIZE = 110;
int N, r, c, d, g, maze[SIZE][SIZE];
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c >> r >> d >> g;
        maze[r][c] = 1;
        vector<int> dir;
        dir.push_back(d);
        for (int j = 0; j < g; j++) {
            int sz = dir.size();
            for (int j = sz - 1; j >= 0; j--) {
                d = dir[j];
                dir.push_back((d + 1) % 4);
            }
        }
        for (int d : dir) {
            r += roff[d], c += coff[d];
            maze[r][c] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            ans += min({maze[i][j], maze[i][j + 1], maze[i + 1][j], maze[i + 1][j + 1]});
        }
    }
    cout << ans;
}