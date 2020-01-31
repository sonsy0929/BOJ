#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int f(int n) {
    if (n == 1) return a % c;
    int ret = f(n / 2);
    ret = (1LL * ret * ret) % c;
    if (n & 1) ret = (1LL * ret * a) % c;
    return ret;
}
int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", f(b));
}