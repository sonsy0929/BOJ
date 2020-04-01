/*
�ð����⵵ : O(NloglogN)

�Ҽ� �Ǻ� �˰������� �Ҽ��� �Ǻ��س����鼭 �縰������� Ȯ���ϸ� �ȴ�.
�� ��, overflow�� �����ؾ� �ϸ� 100�� ���� ū �Ҽ� �߿� �縰����̸鼭,
���� ������ �������� �ľ��ϴ°� �߿��ߴ�.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1'003'001;
bool isPrime[MAX + 1];
int main() {
    int N;
    scanf("%d", &N);
    vector<int> prime(1, 2);
    fill(isPrime + 2, isPrime + MAX + 1, true);
    for (int i = 4; i <= MAX; i += 2) isPrime[i] = false;
    for (ll i = 3; i <= MAX; i += 2) {
        if (!isPrime[i]) continue;
        int k = i, r = 0;
        while (k) {
            r = r * 10 + k % 10;
            k /= 10;
        }
        if (i == r) prime.push_back(i);
        for (ll j = i * i; j <= MAX; j += i * 2) isPrime[j] = false;
    }
    printf("%d", *lower_bound(prime.begin(), prime.end(), N));
}