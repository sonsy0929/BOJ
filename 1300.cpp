/*
시간복잡도 : O(N * log k)

파라메트릭 서치를 이용해서 답을 역추적 해보자.
임의의 숫자 k를 골라서 K번째 숫자인지 판단하면 된다.
그렇다면 k보다 작은 숫자의 개수를 어떻게 하면 빠르게 구할 수 있을까?
A[i][j]에서, i행에 속한 숫자들은 i*j이므로 모두 i의 배수이다.
예를 들어, i행의 숫자들은 i * 1, i * 2, i * 3, ... , i * N으로 구성되어 있다.
i행의 숫자들 중 k보다 작거나 같은 숫자는 (i * j <= k)를 만족하는 j의 개수이고,
이는 i * 1, i * 2, ... , i * j이므로 m / i와 같은 값이 된다.
그러므로, k보다 작은 숫자의 개수를 구할 때 cnt += min(k / i, N);를 더해주면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
int N, K;
bool f(int k) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) cnt += min(k / i, N);
    return cnt >= K;
}
int main() {
    scanf("%d %d", &N, &K);
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d", hi);
}