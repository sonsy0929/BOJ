/*
dp[curr][hasMento] : curr이 curr의 사수와
멘토링을 맺을 때,
혹은 멘토링을 맺지 않을 때,
curr의 '서브트리'에서의 시너지의 합이 최대값

i) curr이 curr의 사수와 멘토링을 맺을 때
curr은 이미 멘토가 있으니, curr의 부사수들은 curr과 멘토링을 맺을 수 없다.
따라서, curr의 부사수들의 '서브트리'에서 합을 더해주면 된다.
curr의 부사수들을 C1, C2, C3, C4 ... 라고 한다면

dp[curr][1] = sum of dp[Cx][0] (1 <= x <= k)

ii) curr이 curr의 사수와 멘토링을 맺지 않을 때
i)에서 추가로, curr과 curr의 부사수 한명이 멘토링을 하는 경우도 고려해야 한다.
dp[curr][0] = max{
    
    sum of dp[Cx][0] => curr이 아무와도 멘토링 하지 않음

    실력[curr] * 실력[C1] + dp[C1][1] + dp[C2][0] + ... => curr과 C1이 멘토링을 맺음
    실력[curr] * 실력[C2] + dp[C1][0] + dp[C2][1] + ... => curr과 C2가 멘토링을 맺음
    ...
}

실력[curr] * 실력[C1] + dp[C1][1] + dp[C2][0] + ... (1)
실력[curr] * 실력[C2] + dp[C1][0] + dp[C2][1] + ... (2)
...

을 전부 일일이 구하면 O(C^2)의 시간이 소요되어 너무 오래 걸린다.
따라서, S = dp[C1][0]+ dp[C2][0] + dp[C3][0] + ...을 미리 O(C)로 구해놓고,

(1) = S - dp[C1][0] + dp[C1][1] + 실력[curr] * 실력[C1]
(2) = S - dp[C2][0] + dp[C2][1] + 실력[curr] * 실력[C2]

이런 방법으로 구한다면, 하나당 O(1)에 구할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 200'010;
int N, dp[SIZE][2], score[SIZE];
vector<int> adj[SIZE];
int f(int curr, bool select) {
    int &ret = dp[curr][select];
    if (ret != -1) return ret;
    int sum = 0;
    for (int next : adj[curr]) {
        sum += f(next, false);
    }
    ret = sum;
    if (!select) {
        for (int next : adj[curr]) {
            int val = score[next] * score[curr];
            ret = max(ret, sum - f(next, false) + f(next, true) + val);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= N; i++) cin >> score[i];
    memset(dp, -1, sizeof(dp));
    cout << f(1, false) << "\n";
}