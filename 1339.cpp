/*
시간복잡도 : O(N * L)
N : 문자열의 개수, L : 문자열의 길이

백트래킹으로도 풀 수 있지만, 그리디로 쉽게 풀 수 있다.
각 알파벳의 자리수에 가중치를 두어 표현하면,
GCF = 100 * G + 10 * C + 1 * F
ACDEB = 10000 * A + 1000 * C + 100 * D + 10 * E + 1 * B
와 같이 표현을 할 수 있다.
이를 더해서 단어의 합이 최대값임을 출력하는 것이므로,
10000 * A + 1010 * C + 100 * G + 100 * D + 10 * E + 1 * B + 1 * F
와 같이 표현할 수 있다.
따라서, 자릿수가 높은 알파벳부터 큰 수를 할당하는 것이 합의 최대값이 나오는 것은 자명하다.
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