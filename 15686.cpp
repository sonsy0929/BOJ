/*
시간복잡도 : O(2^M)

비트마스킹을 이용해서 조합(폐업하지 않은 치킨가게)을 구하고, 집과 가게의 거리를 구하면 된다. 
*/

#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;
const int INF = 1e9;
int N, M, maze[50][50];
vector<p> house, chicken;
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
            if (maze[i][j] == 1) house.push_back({i, j});
            if (maze[i][j] == 2) chicken.push_back({i, j});
        }
    }
    int ans = INF, K = chicken.size();
    for (int b = 0; b < (1 << K); b++) {
        if (__builtin_popcount(b) == M) {
            vector<p> alive;
            for (int i = 0; i < K; i++) {
                if (b & (1 << i)) alive.push_back(chicken[i]);
            }
            int sum = 0;
            for (auto [hr, hc] : house) {
                int dist = INF;
                for (auto [cr, cc] : alive) {
                    dist = min(dist, abs(hr - cr) + abs(hc - cc));
                }
                sum += dist;
            }
            ans = min(ans, sum);
        }
    }
    printf("%d", ans);
}