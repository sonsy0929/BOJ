/*
시간복잡도 : O(N^2)

정렬이 된 상태에서, 하나를 고정시키고 나머지 2개를 양방향 탐색으로 푸는 방법이다.
하나를 고정 [i] 했으므로, [left] + [right] == -[i]에 근사하면 값이 0에 가까워진다.
즉, 기존의 투포인터 방법(양방향 탐색)과 동일하게 사용할 수 있다.
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;
int N;
vector<int> water;
ll getSum(int i, int l, int r) {
    return 0LL + water[i] + water[l] + water[r];
}
int main() {
    fastio;
    cin >> N;
    water.resize(N);
    for (int i = 0; i < N; i++) cin >> water[i];
    sort(water.begin(), water.end());
    ll mn = 1e18;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int l = i + 1, r = N - 1;
        while (l < r) {
            ll sum = getSum(i, l, r);
            if (abs(sum) < mn) {
                mn = abs(sum);
                ans = {water[i], water[l], water[r]};
            }
            if (sum > 0) r--;
            else l++;
        }
    }
    for (int e : ans) cout << e << " ";
}