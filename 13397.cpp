/*
�ð����⵵ : O(Nlog10000)

�Ķ��Ʈ�� ��ġ�� �̿��ؼ� Ǯ �� �ִ�. 
�� ���� ������ ������ x������ �θ� '���������Լ�'���� ���� �� �ִ�. 
�̸� ���� �̺�Ž���� �̿��Ͽ� ������ ������ �ٿ������鼭 '������ ������ �ִ밪�� �ּ�'�� ���� �� �ִ�.
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, v[5000];
bool isPossible(int mid) {
    int mx = 0, mn = 1e9;
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        if (mx - mn > mid) {
            cnt++;
            mx = mn = v[i];
        }
    }
    return cnt <= M;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", v + i);
    int lo = -1, hi = 10007;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%d", hi);
}