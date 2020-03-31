/*
다양한 방법으로 풀 수 있는 문제!!
1) bfs + 파라메트릭 서치
2) 크루스칼
3) 다익스트라

1) bfs + 파라메트릭 서치
시간복잡도 : O((n+m)logC)
구하고자 하는 것은 '한 번의 이동에서 옮길 수 있는 물품들의 중량의 최대값'이다.
조금 생각해보면, '단조 감소 함수'모양으로 함수가 그려지는 것을 확인할 수 있고, 
파라메트릭 서치를 이용해서 답을 구할 수 있다.
정답의 범위(물품의 중량)를 이분 탐색을 통해 절반씩 나누어가면서, 
출발점 -> 도착점으로 도착할 수 있는지 확인한다. 이를 통해, 점점 k(~ 최대값)에 가까워지며,
k값에 도달하면 이를 출력하면 된다. 

2) 크루스칼
시간복잡도 : O(ElogE)
간선들의 가중치를 내림차순으로 정렬해서 각 정점들을 연결해주고,
시작정점과 도착정점이 연결된다면, 이것이 한번의 이동으로 옮길 수 있는 물품들의 중량 최대값이다.
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