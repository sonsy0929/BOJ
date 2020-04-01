/*
�ð����⵵ : O(L * t)

���� deque�� ����(front : ����, ...(����)...., back : �Ӹ�)

�Ǽ��ߴ� �κ� :

1) 0 base�� ��������
(0,0)�� �������� �ƴ϶� (1,1)�� �������̴�

2) ���İ��� �ľ�
������ �ٲ� �� ���� ��, �Ӹ��� ���� �����̰� ������ ��ȯ�� �� ������ ������ �ٲٴ� ���̴�.

3) ���� ����� ġ����
����� �Ծ����� board���� �������� �ʴ´�.
����, ���� ������ ����� �ִ� ������ �ٽ� �������� ��,
����� �����Ѵٸ� ���� ���̰� �þ�� �ȴ�.
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