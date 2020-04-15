/*
문제 이해가 중요했던 문제
만약, 진실을 아는 사람과 같은 모임에 참가한 사람이 있다면,
그 사람이 참여한 다른 모임에서도, 진실을 들어야 모순이 생기지 않고 들키지 않는다.
순서와 상관없이, 만약 다른 모임에서 과장된 얘기를 듣게 되면, 이는 거짓말한 것이므로 들통난다.
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int N, M, C;
bool used[51];
vector<int> adj[51];
void dfs(int curr) {
    used[curr] = true;
    for (int next : adj[curr]) {
        if (!used[next] && next) dfs(next);
    }
}
int main() {
    fastio;
    cin >> N >> M >> C;
    vector<int> noLie;
    while(C--) {
        int p;
        cin >> p;
        noLie.push_back(p);
    }
    vector<int> Q[51];
    for (int i = 0, u, v; i < M; i++) {
        cin >> C;
        u = 0;
        while (C--) {
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            Q[i].push_back(v);
            u = v;
        }
    }
    for (int curr : noLie) dfs(curr);
    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool f = true;
        for (int curr : Q[i]) {
            f &= !used[curr];
        }
        ans += f;
    }
    cout << ans;
}