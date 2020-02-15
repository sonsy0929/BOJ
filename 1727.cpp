/*
�׸���� �����ϸ� �ȵ�.
���� ���̽�)
���� : 1, 2, 4, 4 / ���� : 3, 3, 3
�׸���� �ϸ� 2 + 1 + 1 = 4�� ��������
������ 1 + 1 + 1 = 3�̴�.
������ ���ڰ� ����° ���� Ȥ�� �׹�° ���ڿ� ¦�� ������ �� ��ü�δ� ���̰� ������,
�� ���� �������� ���� �ι�°�� ù���� ���ڰ� �� �� �ִ� ���ÿ� ������ �ΰ� �ȴ�.

�� �׸��� �ƴ� ����, ������ dp�� ������ �� ������,
dp[n][m] = ���� n��� ���� m���� �ִ��� ���� Ŀ���� �������� �� ������ ������ �ּ����̶� ���� �ϸ�
dp[n][m] = min(dp[n-1][m], dp[n-1][m-1] + abs(cost[n] - cost[m]))
�̸� �̿��� ������ ���ϸ� �ȴ�. 

�ð����⵵ : O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, MAN[1000], WOMAN[1000], dp[1000][1000];
int f(int i, int j) {
    if (i == N) return 0;
    if (j == M) return 1e9;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = f(i, j + 1);
    ret = min(ret, f(i + 1, j + 1) + abs(MAN[i] - WOMAN[j]));
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", MAN + i);
    for (int i = 0; i < M; i++) scanf("%d", WOMAN + i);
    if (N >= M) {
        swap(N, M);
        swap(MAN, WOMAN);
    }
    memset(dp, -1, sizeof(dp));
    sort(MAN, MAN + N);
    sort(WOMAN, WOMAN + M);
    printf("%d\n", f(0, 0));
}