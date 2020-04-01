/*
�ð����⵵ : O(N * k)
k : �� ���밡 �󸶳� ������ �� �ִ���

K - 1 ���뿡�� K ����� �����ϴµ� ��Ģ�� �־�����,
�̴� �ͳ������� ������ �� ������ �ǹ��Ѵ�.
K - 1 ������ ������� K ����� �Ѿ�� �� ���� ���� ������ ������� �ڿ������� ������ 
�ݽð� �������� ȸ���ϴ� ���� Ȯ���� �� �ִ�.
�̸� ���� ������ �� ���뺰�� �׾ư��� ���� ��ǥ���� ���⿡ ���� �̵� �ϸ鼭
�湮ó���� ���ָ� �ȴ�. �׸���, �簢���� �����ϴ��� 100 * 100�� ���鼭 Ȯ���ϸ� �ȴ�.
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