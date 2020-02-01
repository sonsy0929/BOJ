#include <bits/stdc++.h>
using namespace std;
int N, K, paper[100'000];
bool isPossible(int n) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < N; i++) {
        sum += paper[i];
        if (sum > n) {
            cnt++;
            sum = 0;
        }
    }
    return cnt <= K;
}
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", paper + i);
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%d\n", hi);
}