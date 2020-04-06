/*
시간복잡도 : O((N+M)2^N)

비트마스킹을 통해 선거구를 나누었다.
ex) 1000101 => R 선거구 : (0, 2, 6), B 선거구 : (1, 3, 4, 5)
이후, dfs를 통해 올바르게 선거구가 연결이 되었는지 확인하고
올바르게 연결이 되었다면 두 선거구의 인구 차이를 통해 최소값을 갱신

실수한 부분)
1. 문제이해 미숙
다른 선거구를 통해서 연결이 되어있어도 올바른 선거구라고 잘못 이해함..

반례)
4
8 10 5 2
2 4 2
3 1 4 3
2 2 4
3 1 2 3
오답 : 1
정답 : 5

2. 유향 그래프 X, 무향 그래프 O
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int SIZE = 10;
int N, people[SIZE];
vector<int> adj[SIZE];
void dfs(int curr, vector<int>& visited) {
    visited[curr] = 1;
    for (int next : adj[curr]) {
        if (!visited[next]) dfs(next, visited);
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", people + i);
    for (int i = 0; i < N; i++) {
        int sz, to;
        scanf("%d", &sz);
        for (int j = 0; j < sz; j++) {
            scanf("%d", &to);
            adj[i].push_back(to - 1);
            adj[to - 1].push_back(i);
        }
    }
    int ans = INF;
    for (int b = 0; b < 1 << N; b++) {
        vector<int> R, B, RisConnected(SIZE), BisConnected(SIZE);
        for (int i = 0; i < N; i++) {
            if (b & (1 << i)) {
                R.push_back(i);
                BisConnected[i] = true;
            } else {
                B.push_back(i);
                RisConnected[i] = true;
            }
        }
        if (R.size()) dfs(R.front(), RisConnected);
        if (B.size()) dfs(B.front(), BisConnected);
        int rSum = 0, bSum = 0;
        bool rFlag = R.size(), bFlag = B.size();
        for (int e : R) {
            rFlag &= RisConnected[e];
            rSum += people[e];
        }
        for (int e : B) {
            bFlag &= BisConnected[e];
            bSum += people[e];
        }
        if (rFlag && bFlag) {
            ans = min(ans, abs(rSum - bSum));
        }
    }
    printf("%d\n", ans != INF ? ans : -1);
}