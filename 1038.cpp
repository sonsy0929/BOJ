/*
디스크립션의 내용대로라면, 가장 큰 감소하는 수가 '9876543210' 임은 자명한 사실이다.
이를 통해, k = 1 ~ 10까지 10개 중에 중복없이 k개를 뽑아 감소하는 수인지 확인하면 된다.
이 때, '9876543210'은 int 범위를 넘어선다는 것에 주의를 해야 한다. 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
set<ll> used;
vector<ll> decreaseNums;
void comb(int cnt, ll num) {
    if (cnt > 10) return;
    for (int i = 0; i < 10; i++) {
        if (num && num % 10 <= i) continue;
        if (!used.count(num * 10 + i)) {
            used.insert(num * 10 + i);
            decreaseNums.push_back(num * 10 + i);
            comb(cnt + 1, num * 10 + i);
        }
    }
}
int main() {
    scanf("%d", &N);
    comb(0, 0LL);
    sort(decreaseNums.begin(), decreaseNums.end());
    if (decreaseNums.size() <= N)
        puts("-1");
    else
        printf("%lld", decreaseNums[N]);
}