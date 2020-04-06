/*
�ð����⵵ : O((N+M)2^N)

��Ʈ����ŷ�� ���� ���ű��� ��������.
ex) 1000101 => R ���ű� : (0, 2, 6), B ���ű� : (1, 3, 4, 5)
����, dfs�� ���� �ùٸ��� ���ű��� ������ �Ǿ����� Ȯ���ϰ�
�ùٸ��� ������ �Ǿ��ٸ� �� ���ű��� �α� ���̸� ���� �ּҰ��� ����

�Ǽ��� �κ�)
1. �������� �̼�
�ٸ� ���ű��� ���ؼ� ������ �Ǿ��־ �ùٸ� ���ű���� �߸� ������..

�ݷ�)
4
8 10 5 2
2 4 2
3 1 4 3
2 2 4
3 1 2 3
���� : 1
���� : 5

2. ���� �׷��� X, ���� �׷��� O
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