/*
(a + b) % M = a % M + b % M
(a - b) % M = a % M - b % M
나머지가 같은 것 끼리 빼면 0이기 때문에, 위 공식을 통해 나머지가 같은 것들을 그룹지어주고,
2쌍을 고르는 것을 count해주면 임의의 (i, j) 2쌍의 개수를 구할 수 있다.
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