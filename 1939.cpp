/*
�پ��� ������� Ǯ �� �ִ� ����!!
1) bfs + �Ķ��Ʈ�� ��ġ
2) ũ�罺Į
3) ���ͽ�Ʈ��

1) bfs + �Ķ��Ʈ�� ��ġ
�ð����⵵ : O((n+m)logC)
���ϰ��� �ϴ� ���� '�� ���� �̵����� �ű� �� �ִ� ��ǰ���� �߷��� �ִ밪'�̴�.
���� �����غ���, '���� ���� �Լ�'������� �Լ��� �׷����� ���� Ȯ���� �� �ְ�, 
�Ķ��Ʈ�� ��ġ�� �̿��ؼ� ���� ���� �� �ִ�.
������ ����(��ǰ�� �߷�)�� �̺� Ž���� ���� ���ݾ� ������鼭, 
����� -> ���������� ������ �� �ִ��� Ȯ���Ѵ�. �̸� ����, ���� k(~ �ִ밪)�� ���������,
k���� �����ϸ� �̸� ����ϸ� �ȴ�. 

2) ũ�罺Į
�ð����⵵ : O(ElogE)
�������� ����ġ�� ������������ �����ؼ� �� �������� �������ְ�,
���������� ���������� ����ȴٸ�, �̰��� �ѹ��� �̵����� �ű� �� �ִ� ��ǰ���� �߷� �ִ밪�̴�.
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using p = pair<int, int>;
int N, M, S, E, uf[10001];
struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) {
        return w > o.w;
    }
};
int find(int n) {
    if (uf[n] < 0) return n;
    return uf[n] = find(uf[n]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    uf[u] = v;
}
int main() {
    fastio;
    cin >> N >> M;
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cin >> S >> E;
    memset(uf, -1, sizeof(uf));
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto [u, v, w] : edges) {
        merge(u, v);
        ans = w;
        if (find(S) == find(E)) break;
    }
    cout << ans;
}