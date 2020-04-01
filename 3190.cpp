/*
시간복잡도 : O(L * t)

뱀을 deque로 구현(front : 꼬리, ...(몸통)...., back : 머리)

실수했던 부분 :

1) 0 base로 생각한점
(0,0)이 시작점이 아니라 (1,1)이 시작점이다

2) 전후관계 파악
방향을 바꿀 수 있을 때, 머리가 먼저 움직이고 방향을 변환할 수 있으면 방향을 바꾸는 것이다.

3) 먹은 사과는 치우자
사과를 먹었으면 board에는 존재하지 않는다.
만약, 뱀이 이전에 사과가 있던 곳으로 다시 접근했을 때,
사과가 존재한다면 뱀의 길이가 늘어나게 된다.
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using p = pair<int, int>;
const int roff[] = {-1, 0, 1, 0};
const int coff[] = {0, -1, 0, 1};
int N, K, L, board[101][101];
char command[10001];
bool visited[101][101];
bool isIn(int r, int c) {
    return r > 0 && r <= N && c > 0 && c <= N;
}
int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int t;
        char d;
        cin >> t >> d;
        command[t] = d;
    }
    deque<p> snake;
    snake.push_back({1, 1});
    int r = 1, c = 1, d = 3, t = 1;
    for (;; t++) {
        int nr = r + roff[d], nc = c + coff[d];
        snake.push_back({nr, nc});
        if (!isIn(nr, nc) || visited[nr][nc]) break;
        if (!board[nr][nc]) {
            auto [tr, tc] = snake.front();
            visited[tr][tc] = false;
            snake.pop_front();
        }
        visited[nr][nc] = true;
        board[nr][nc] = 0;
        r = nr, c = nc;
        if (command[t] == 'D') {
            d = (d + 3) % 4;
        } else if (command[t] == 'L') {
            d = (d + 1) % 4;
        }
    }
    cout << t;
}