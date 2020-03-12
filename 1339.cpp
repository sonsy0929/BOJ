/*
�ð����⵵ : O(N * L)
N : ���ڿ��� ����, L : ���ڿ��� ����

��Ʈ��ŷ���ε� Ǯ �� ������, �׸���� ���� Ǯ �� �ִ�.
�� ���ĺ��� �ڸ����� ����ġ�� �ξ� ǥ���ϸ�,
GCF = 100 * G + 10 * C + 1 * F
ACDEB = 10000 * A + 1000 * C + 100 * D + 10 * E + 1 * B
�� ���� ǥ���� �� �� �ִ�.
�̸� ���ؼ� �ܾ��� ���� �ִ밪���� ����ϴ� ���̹Ƿ�,
10000 * A + 1010 * C + 100 * G + 100 * D + 10 * E + 1 * B + 1 * F
�� ���� ǥ���� �� �ִ�.
����, �ڸ����� ���� ���ĺ����� ū ���� �Ҵ��ϴ� ���� ���� �ִ밪�� ������ ���� �ڸ��ϴ�.
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
int N, W[26];
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        int sz = in.size();
        for (int j = sz - 1, k = 1; j >= 0; j--, k *= 10) {
            W[in[j] - 'A'] += k;
        }
    }
    sort(W, W + 26, greater<int>());
    int ans = 0, k = 9;
    for (int i = 0; W[i]; i++) {
        ans += W[i] * k--;
    }
    cout << ans;
}