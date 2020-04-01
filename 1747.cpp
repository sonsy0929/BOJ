/*
시간복잡도 : O(NloglogN)

소수 판별 알고리즘으로 소수를 판별해나가면서 펠린드롬인지 확인하면 된다.
이 때, overflow에 유의해야 하며 100만 보다 큰 소수 중에 펠린드롬이면서,
가장 작은게 무엇인지 파악하는게 중요했다.
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