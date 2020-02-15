/*
그리디로 접근하면 안됨.
예외 케이스)
남자 : 1, 2, 4, 4 / 여자 : 3, 3, 3
그리디로 하면 2 + 1 + 1 = 4가 나오지만
정답은 1 + 1 + 1 = 3이다.
마지막 여자가 세번째 남자 혹은 네번째 남자와 짝을 짓는지 그 자체로는 차이가 없지만,
그 때의 선택으로 인해 두번째와 첫뻔재 여자가 할 수 있는 선택에 제한을 두게 된다.

즉 그리디가 아닌 선택, 비선택의 dp로 접근할 수 있으며,
dp[n][m] = 남자 n명과 여자 m명이 최대한 많은 커플을 형성했을 때 성격의 차이의 최소합이라 정의 하면
dp[n][m] = min(dp[n-1][m], dp[n-1][m-1] + abs(cost[n] - cost[m]))
이를 이용해 정답을 구하면 된다. 

시간복잡도 : O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, MAN[1000], WOMAN[1000], dp[1000][1000];
int f(int i, int j) {
    if (i == N) return 0;
    if (j == M) return 1e9;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = f(i, j + 1);
    ret = min(ret, f(i + 1, j + 1) + abs(MAN[i] - WOMAN[j]));
    return ret;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", MAN + i);
    for (int i = 0; i < M; i++) scanf("%d", WOMAN + i);
    if (N >= M) {
        swap(N, M);
        swap(MAN, WOMAN);
    }
    memset(dp, -1, sizeof(dp));
    sort(MAN, MAN + N);
    sort(WOMAN, WOMAN + M);
    printf("%d\n", f(0, 0));
}