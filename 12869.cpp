/*
�ð� ���⵵ : O(60^3)

bfs, dp �� �� ������ Ǯ��
���� �� �ִ� ���°����� 60 * 60 * 60 = 60^3 �̰�, ���°����� ä��µ� �ɸ��� �ð� ���⵵�� O(1)�̹Ƿ�
�� �ð� ���⵵�� O(60^3)�̴�.
*/

#include <bits/stdc++.h>
using namespace std;
int N, HP[3], dp[61][61][61];
int f(int a, int b, int c) {
    if (!a && !b && !c) return 0;
    int &ret = dp[a][b][c];
    if (ret != -1) return ret;
    int atk[3] = {1, 3, 9};
    ret = 1e9;
    do {
        ret = min(ret, f(max(0, a - atk[0]), max(0, b - atk[1]), max(0, c - atk[2])) + 1);
    } while (next_permutation(atk, atk + 3));
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", HP + i);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(HP[0], HP[1], HP[2]));
}