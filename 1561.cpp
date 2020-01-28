/*
�Ķ��Ʈ�� ��ġ�� �̿��ؼ� N���� �ο��� ���̱ⱸ�� ž���ϴµ� �ɸ��� �ð� T�� ���� �� �ִ�.
T�� ��������, T - 1�� ���� ���̱ⱸ�� ź ���� ���� ���� ���� �� �ְ�
�̸� �̿��ؼ� �� �������� �� ���� ���̱ⱸ�� Ÿ���� ���� �� �ִ�.
�Ǽ��� �κ��� hi�� 1e18�� �־� cnt�� ����� �� �����÷ο찡 ���� ����� �Ͽ���.
������ 1e15 ������ �־ ����߰�, overflow�� ������ ����� ����� ���ϰ� �� ����ؼ� ��� Ʋ�Ƚ��ϴٸ� �޾Ҵ�.
5e17 * 10000 > 1e19�̴�.. 1e19�� long long���� ǥ�� ���� �� ���� �ִ밪���� overflow�� �� �� �ۿ� ������ �ФФ�..
������ �̷� ���� ����� ����ϰ� �Ķ��Ʈ�� ��ġ�� �������..
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, play[10'000];
bool isPossible(ll mid) {
    ll cnt = M;
    for (int i = 0; i < M; i++) {
        cnt += mid / play[i];
    }
    return cnt >= N;
}
int getCnt(ll lo) {
    int ret = M;
    for (int i = 0; i < M; i++) {
        ret += lo / play[i];
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) scanf("%d", play + i);
    if (N <= M) {
        printf("%d", N);
        return 0;
    }
    ll lo = 0, hi = 1e15;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    int cnt = getCnt(lo), last = 0;
    for (int i = 0; i < M; i++) {
        if (cnt == N) break;
        if (hi % play[i] == 0) {
            last = i + 1;
            cnt++;
        }
    }
    printf("%d\n", last);
}