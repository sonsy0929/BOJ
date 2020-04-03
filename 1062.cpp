#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int ALPHA = 26;
int N, K;
int get() {
    int ret = 0;
    char v[5] = {'a', 'n', 't', 'i', 'c'};
    for (int i = 0; i < 5; i++) {
        ret |= 1 << (v[i] - 'a');
    }
    return ret;
}
int main() {
    cin >> N >> K;
    vector<int> bits;
    for (int i = 0; i < N; i++) {
        int bit = 0; string word;
        cin >> word;
        for (char c : word) {
            bit |= 1 << (c - 'a');
        }
        bits.push_back(bit);
    }
    if (K < 5) {
        cout << 0;
        return 0;
    }
    int ans = 0, necessary = get();
    for (int b = necessary; b < (1 << ALPHA); ++b |= necessary) {
        if (__builtin_popcount(b) == K) {
            int cnt = 0;
            for (int bit : bits) {
                cnt += (bit & b) == bit;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}