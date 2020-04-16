/*
�ð����⵵ : O(N^2)

������ �� ���¿���, �ϳ��� ������Ű�� ������ 2���� ����� Ž������ Ǫ�� ����̴�.
�ϳ��� ���� [i] �����Ƿ�, [left] + [right] == -[i]�� �ٻ��ϸ� ���� 0�� ���������.
��, ������ �������� ���(����� Ž��)�� �����ϰ� ����� �� �ִ�.
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