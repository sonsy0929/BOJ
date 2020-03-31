/*
시간복잡도 : O(4 * 3^N)
=> 왜 4^N이 아닌 4 * 3^N인가?
=> 왔던 길을 다시 되돌아 가는 경우는 제외해야 하기 때문에
*/
#include <bits/stdc++.h>
using namespace std;
const int roff[] = {0, 0, 1, -1};
const int coff[] = {1, -1, 0, 0};
using p = pair<int, int>;
int N; double P[4];
set<p> used;
double f(int depth, int r, int c) {
    if (depth >= N) return 1;
    double ret = 0;
    used.insert({r, c});
    for (int d = 0; d < 4; d++) {
        int nr = r + roff[d], nc = c + coff[d];
        if (used.count({nr, nc})) continue;
        ret += f(depth + 1, nr, nc) * P[d];
    }
    used.erase({r, c});
    return ret;
}
int main() {
    scanf("%d", &N);
    double ans = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%lf", &P[i]);
        P[i] /= 100;
    }
    printf("%.9lf", f(0, 0, 0));
}