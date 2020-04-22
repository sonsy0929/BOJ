/*
시간복잡도 : O(N + k)

https://www.acmicpc.net/problem/2531와 동치인 문제
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int SZ = 3'000'010;
int N, d, k, c, susi[SZ*2], eat[3010];
int main() {
    fastio;
    cin >> N >> d >> k >> c;
    for (int i = 0, in; i < N; i++) {
        cin >> in;
        susi[i] = susi[i+N] = in;
    }
    int s = 0, e = 0, cnt = 0, ans = 0;
    while (e < 2 * N) {
        if (e - s < k) {
            if (!eat[susi[e]]) cnt++;
            eat[susi[e++]]++;
        }
        else {
            ans = max(ans, cnt + !eat[c]);
            if (--eat[susi[s]] == 0) cnt--;
            s++;
        }
    }
    cout << ans;
}