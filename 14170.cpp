/*
시간복잡도 : O(QlogN)

lower_bound와 upper_bound를 통해 해당하는 원소의 개수(A <= k <= B를 만족하는 원소의 개수)를 세어주면 된다.
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
int N, Q;
int main() {
    fastio;
    cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    while (Q--) {
        int A, B;
        cin >> A >> B;
        auto lo = lower_bound(v.begin(), v.end(), A);
        auto hi = upper_bound(v.begin(), v.end(), B);
        cout << hi - lo << "\n";
    }
}