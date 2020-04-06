/*
�ð����⵵ : O(NlogM)

�������� parametric search ����
���ܱ⿡ �����ϴ� ����(���ϰ��� �ϴ� ��, ������ ����)�� ���� �߸��� ������ ���� '���������Լ�'���� ���� �� �ִ�.
����, parametric search�� ����ؼ� ������ �������ϸ� �ȴ�.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, tree[1'000'000];
bool f(int m) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += max(0, tree[i] - m);
    }
    return sum >= M;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", tree + i);
    int lo = 0, hi = 1e9 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) lo = mid;
        else hi = mid;
    }
    printf("%d", lo);
}