/*
���� ���ذ� �߿��ߴ� ����
����, ������ �ƴ� ����� ���� ���ӿ� ������ ����� �ִٸ�,
�� ����� ������ �ٸ� ���ӿ�����, ������ ���� ����� ������ �ʰ� ��Ű�� �ʴ´�.
������ �������, ���� �ٸ� ���ӿ��� ����� ��⸦ ��� �Ǹ�, �̴� �������� ���̹Ƿ� ���볭��.
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