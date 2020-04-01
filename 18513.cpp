/*
시간복잡도 : O(N)

최소값을 얻으려면, 샘터와의 거리가 작은 위치부터 차례대로 집을 놓아야 한다.
즉, 거리가 1인 위치에 전부 집을 넣고, 그래도 집을 더 놓아야 한다면 거리가 2인 위치에
전부 놓고, 같은 방식으로 거리를 1씩 늘려가면서 집을 놓아야 한다.

거리가 1인 위치는 샘터와 인접한 곳이고, 거리가 2인 위치는 거리가 1인 위치와 인접한 곳이다.
즉, 모든 샘터의 위치를 큐에 넣고 BFS를 돌리면서 집을 설치하면 된다는 것을 알 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
set<int> used;
int n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    queue<p> q;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        q.push({0, in});
        used.insert(in);
    }
    long long ans = 0;
    int cnt = 0;
    int addVal[2] = {1, -1};
    while (!q.empty()) {
        auto [d, f] = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nf = f + addVal[i];
            if (!used.count(nf)) {
                used.insert(nf);
                q.push({d + 1, nf});
                ans += d + 1;
                if (++cnt >= k) {
                    cout << ans;
                    return 0;
                }
            }
        }
    }
}