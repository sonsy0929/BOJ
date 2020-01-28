/*
파라메트릭 서치를 이용해서 N명의 인원이 놀이기구를 탑승하는데 걸리는 시간 T를 구할 수 있다.
T를 구했으면, T - 1초 동안 놀이기구를 탄 아이 수를 쉽게 구할 수 있고
이를 이용해서 맨 마지막에 몇 번의 놀이기구를 타는지 구할 수 있다.
실수한 부분은 hi를 1e18로 주어 cnt를 계산할 때 오버플로우가 나게 계산을 하였다.
본래는 1e15 정도만 주어도 충분했고, overflow가 나는지 제대로 계산을 안하고 막 사용해서 계속 틀렸습니다를 받았다.
5e17 * 10000 > 1e19이다.. 1e19는 long long으로 표현 했을 때 거진 최대값으로 overflow가 날 수 밖에 없었다 ㅠㅠㅠ..
앞으로 이런 점도 제대로 계산하고 파라메트릭 서치를 사용하자..
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, play[10'000];
bool isPossible(ll mid) {
    ll cnt = M;
    for (int i = 0; i < M; i++) {
        cnt += mid / play[i];
    }
    return cnt >= N;
}
int getCnt(ll lo) {
    int ret = M;
    for (int i = 0; i < M; i++) {
        ret += lo / play[i];
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) scanf("%d", play + i);
    if (N <= M) {
        printf("%d", N);
        return 0;
    }
    ll lo = 0, hi = 1e15;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    int cnt = getCnt(lo), last = 0;
    for (int i = 0; i < M; i++) {
        if (cnt == N) break;
        if (hi % play[i] == 0) {
            last = i + 1;
            cnt++;
        }
    }
    printf("%d\n", last);
}