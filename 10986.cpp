/*
(a + b) % M = a % M + b % M
(a - b) % M = a % M - b % M
�������� ���� �� ���� ���� 0�̱� ������, �� ������ ���� �������� ���� �͵��� �׷������ְ�,
2���� ���� ���� count���ָ� ������ (i, j) 2���� ������ ���� �� �ִ�.
*/
#include <bits/stdc++.h>
using namespace std;
int N, M, cnt[1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    long long sum = 0, ans = 0;
    cnt[0] = 1;
    for (int i = 0; i < N; i++) {
        int in;
        cin >> in;
        sum = (sum + in) % M;
        ans += cnt[sum]++;
    }
    cout << ans;
}