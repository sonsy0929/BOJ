/*
시간복잡도 : O(NlogM)

전형적인 parametric search 문제
절단기에 설정하는 높이(구하고자 하는 것, 정답의 범위)에 따라 잘리는 나무의 합이 '단조감소함수'임을 보일 수 있다.
따라서, parametric search를 사용해서 정답을 역추적하며 된다.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, tree[1'000'000];
bool f(int m) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += max(0, tree[i] - m);
    }
    return sum >= M;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", tree + i);
    int lo = 0, hi = 1e9 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) lo = mid;
        else hi = mid;
    }
    printf("%d", lo);
}