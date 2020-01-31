#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long f(int k, int n) {
    if (n == 1) return k;
    long long ret = f(k, n / 2);
    ret = (ret * ret) % MOD;
    if (n & 1) ret = (ret * k) % MOD;
    return ret;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int N;
        scanf("%d", &N);
        if (N <= 2) {
            puts("1");
        } else {
            printf("%d\n", f(2, N - 2) % MOD);
        }
    }
}