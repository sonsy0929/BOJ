/*
시간복잡도 : O(N!)

N = 4라면

1 -> 2 -> 3 -> 4 -> 1
1 -> 3 -> 2 -> 4 -> 1
...
2 -> 1 -> 3 -> 4 -> 2
2 -> 3 -> 1 -> 4 -> 2
...
3 -> 1 -> 2 -> 4 -> 3
...
4 -> 1 -> 2 -> 3 -> 4
...

와 같이 4!의 TSP 경로가 나오게 되고, 이 중에서 최소비용을 구하면 된다.
실수한 부분으로는, '도시 i에서 도시 j로 갈 수 없는 경우도 있으며 이럴 경우 W[i][j]=0이라고 하자.' 
이 문장을 제대로 읽지 못해서, 갈 수 없는 TSP 경로를 제해주지 못했다.
*/

#include <bits/stdc++.h>
using namespace std;
int N, W[11][11];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &W[i][j]);
        }
    }
    vector<int> permu;
    for (int i = 1; i <= N; i++) permu.push_back(i);
    int ans = 1e9;
    do {
        permu.push_back(permu[0]);
        int sum = 0, u, v;
        int sz = permu.size();
        bool possible = true;
        for (int i = 0; i < sz - 1; i++) {
            u = permu[i], v = permu[i + 1];
            sum += W[u][v];
            possible &= W[u][v] != 0;
        }
        permu.pop_back();
        if (!possible) continue;
        ans = min(ans, sum);
    } while (next_permutation(permu.begin(), permu.end()));
    printf("%d", ans);
}