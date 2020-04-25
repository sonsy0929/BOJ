#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll a, b, s = 0;
    cin >> a >> b;
    int k = 0;
    for (; k < 60; k++) {
        s += (1LL << k);
        if (s % b == 0) break;
    }
    if (k >= 60) return !printf("-1");
    a *= s / b;
    bitset<64> bs(a);
    for (int i = k; i >= 0; i--) {
        if (bs[i]) cout << "*";
        else cout << "-";
    }
}