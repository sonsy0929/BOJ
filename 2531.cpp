/*
����!! ����!! ����!!
�� ������ ����������, �����̹Ƿ� �̿� ���� ó���� ���ָ� ���� Ǯ �� �ִ�.
*/
#include <bits/stdc++.h>
using namespace std;
constexpr int SIZE = 60010;
int N, d, k, c, susi[SIZE], used[SIZE];
int main() {
    scanf("%d %d %d %d", &N, &d, &k, &c);
    for (int i = 0; i < N; i++) {
        scanf("%d", susi + i);
        susi[i + N] = susi[i];
    }
    int ans = 0, cnt = 0, s = 0, e = 0;
    while (e <= 2 * N) {
        if (e - s < k) {
            if (!used[susi[e]]) cnt++;
            used[susi[e++]]++;
        } else {
            int plusCnt = used[c] == 0;
            ans = max(ans, cnt + plusCnt);
            used[susi[s]]--;
            if (!used[susi[s++]]) cnt--;
        }
    }
    printf("%d\n", ans);
}