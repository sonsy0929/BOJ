/*
�ð����⵵ : O(N * log k)

�Ķ��Ʈ�� ��ġ�� �̿��ؼ� ���� ������ �غ���.
������ ���� k�� ��� K��° �������� �Ǵ��ϸ� �ȴ�.
�׷��ٸ� k���� ���� ������ ������ ��� �ϸ� ������ ���� �� ������?
A[i][j]����, i�࿡ ���� ���ڵ��� i*j�̹Ƿ� ��� i�� ����̴�.
���� ���, i���� ���ڵ��� i * 1, i * 2, i * 3, ... , i * N���� �����Ǿ� �ִ�.
i���� ���ڵ� �� k���� �۰ų� ���� ���ڴ� (i * j <= k)�� �����ϴ� j�� �����̰�,
�̴� i * 1, i * 2, ... , i * j�̹Ƿ� m / i�� ���� ���� �ȴ�.
�׷��Ƿ�, k���� ���� ������ ������ ���� �� cnt += min(k / i, N);�� �����ָ� �ȴ�.
*/
#include <bits/stdc++.h>
using namespace std;
int N, K;
bool f(int k) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) cnt += min(k / i, N);
    return cnt >= K;
}
int main() {
    scanf("%d %d", &N, &K);
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d", hi);
}