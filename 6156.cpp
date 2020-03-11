/*
시간복잡도 : O(N^3)

소들의 순위를 어떻게 결정지을 수 있는지가 중요한 문제였다.
N마리의 소 중에서 어떤 소의 순위를 명확하게 하려면,
어떤 소를 제외하고 N - 1마리 소와의 대소관계가 명확해야 한다.
즉, 자신보다 실력이 뛰어난 소의 수와 
자신보다 실력이 떨어지는 소의 수를 계산하면 알 수 있다. 
N마리의 소 중에서 자신보다 뛰어난 소의 수가 A, 떨어지는 소의 수를 B라 하면, 
A + B = N - 1이면 그 소의 순위를 결정 지을 수 있다.

이를, 단방향 그래프에서 각 정점간의 연결여부 문제로 바꾸어 볼 수 있고,
이는 dfs, bfs, 플로이드를 통해서 연결이 되었는지 확인할 수 있다.
플로이드가 구현하기 더 편해서 플로이드로 구현했다.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, cow[101][101];
int main() {
    memset(cow, INF, sizeof(cow));
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        cow[u][v] = 1;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cow[i][j] = min(cow[i][j], cow[i][k] + cow[k][j]);
            }
        }
    }
    int cnt[101]{}, ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cow[i][j] != INF) {
                cnt[i]++, cnt[j]++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        ans += cnt[i] == N - 1;
    }
    printf("%d", ans);
}