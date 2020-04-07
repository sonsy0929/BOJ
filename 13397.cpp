/*
시간복잡도 : O(Nlog10000)

파라메트릭 서치를 이용해서 풀 수 있다. 
이 또한 정답의 범위를 x축으로 두면 '단조증가함수'임을 보일 수 있다. 
이를 통해 이분탐색을 이용하여 정답의 범위를 줄여나가면서 '구간의 점수의 최대값의 최소'를 구할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, v[5000];
bool isPossible(int mid) {
    int mx = 0, mn = 1e9;
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        if (mx - mn > mid) {
            cnt++;
            mx = mn = v[i];
        }
    }
    return cnt <= M;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", v + i);
    int lo = -1, hi = 10007;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%d", hi);
}