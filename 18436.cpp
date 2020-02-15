/*
�ð� ���⵵ : O(QlogN)
Ȧ���� ������ �����ϴ� ����Ʈ���� ¦���� ������ �����ϴ� ����Ʈ���� �����ϸ� ��
*/
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100'010;
int N, Q, sum[SIZE][2], A[SIZE];
void update(int i, int d, int k) {
    while (i <= N) {
        sum[i][k] += d;
        i += (i & -i);
    }
}
int query(int i, int k) {
    int ret = 0;
    while (i) {
        ret += sum[i][k];
        i -= (i & -i);
    }
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", A + i);
        update(i, 1, A[i] & 1);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int q, l, r;
        scanf("%d %d %d", &q, &l, &r);
        if (q == 1) {
            update(l, -1, A[l] & 1);
            A[l] = r;
            update(l, 1, A[l] & 1);
        } else {
            printf("%d\n", query(r, q - 2) - query(l - 1, q - 2));
        }
    }
}